/* --------------------------------------------------------------------
 * Library for Sparkfun Si4703 breakout board.
 * 01/02/2009 : Nathan Seidle from Sparkfun.
 * 09/09/2011 : Simon Monk.
 * 11/02/2013 - Fixed for Arduino 1.0. Changed wire.send and wire.receive to wire.write and wire.read. Also added arduino.h and removed wprogram.h
 * 27/09/2015 : Velleman: Implemented new readRDS method based on work by Martin Marinov.
		            Added some code to clear the radiotext (RDS) buffer when seeking and setting the channel.
 * 13/04/2020 : David de Lorenzo. 
*/

#include "Arduino.h"
#include "SparkFunSi4703.h"
#include "Wire.h"

// --------------------------------------------------------------------
// Constructor
// --------------------------------------------------------------------
Si4703_Breakout::Si4703_Breakout(int resetPin, int sdioPin, int sclkPin, int stcIntPin)
{
  _resetPin  = resetPin;
  _sdioPin   = sdioPin;
  _sclkPin   = sclkPin;
  _stcIntPin = stcIntPin;
}

// --------------------------------------------------------------------
// Hardware initialization
// --------------------------------------------------------------------
void Si4703_Breakout::powerOn()
{
  si4703_init();
}

// --------------------------------------------------------------------
// Bande 00 (default) = US/EUROPE = 87.5-105 MHz   -> channel 0 = 87.5
// Channel spacing = 0.1 MHz for Europe  (0.2 MHz for USA)
// Parameter freq = frequency value [875 ... 1050] (unit = 100 kHz)
// --------------------------------------------------------------------
void Si4703_Breakout::setChannel(int freq)
{
  int newChannel = freq - 875 ;   // Ex: 93.5 MHz => 935-875 = channel

  //These steps come from AN230 page 20 rev 0.5
  readRegisters();
  si4703_registers[CHANNEL] &= 0xFE00;      // Clear out the channel bits
  si4703_registers[CHANNEL] |= newChannel;  // Mask in the new channel
  si4703_registers[CHANNEL] |= (1 << TUNE); // Set the TUNE bit to start
  updateRegisters();
  delay(60);                // Wait 60ms - you can use or skip this delay

  // Poll to see if STC is set
  while (1)
  {
    readRegisters();
    if ( (si4703_registers[STATUSRSSI] & (1 << STC)) != 0) break; //Tuning complete!
  }
  //Serial.println("_stcIntPin passed");

  readRegisters();
  si4703_registers[CHANNEL] &= ~(1 << TUNE); // Clear the tune after a tune has completed
  updateRegisters();

  // Wait for the si4703 to clear the STC as well
  while (1)
  {
    readRegisters();
    if ( (si4703_registers[STATUSRSSI] & (1 << STC)) == 0) break; // Tuning complete!
  }
  // clear radiotext buffer on channel change
  for (int i = 0; i < 65; i++)
  {
    radiotext[i] = 0;
  }
}

// --------------------------------------------------------------------
// Reads the current channel from register READCHAN
// Returns a number like 973 for 97.3MHz (=frequency with unit 100kHz)
// Europe: Freq(MHz) = 0.1*Channel + 87.5MHz   <=> Freq(100kHz) = Channel + 875
// --------------------------------------------------------------------
int Si4703_Breakout::getChannel()
{
  readRegisters();
  // Mask out everything but the lower 10 bits
  int channel = si4703_registers[READCHAN] & 0x03FF; 
  int frequency = channel + 875;
  return (frequency);
}

// --------------------------------------------------------------------
// Seeks out the next available station.
// Returns the frequency found, or 0 if failed.
// --------------------------------------------------------------------
int Si4703_Breakout::seekUp()
{
  return seek(SEEK_UP);
}

// --------------------------------------------------------------------
// Seeks out the next available station.
// Returns the frequency found, or 0 if failed.
// --------------------------------------------------------------------
int Si4703_Breakout::seekDown()
{
  return seek(SEEK_DOWN);
}

// --------------------------------------------------------------------
// Set the volume
// parameter: 0..15 (ie: bits 0000 to 1111)
// --------------------------------------------------------------------
void Si4703_Breakout::setVolume(int volume)
{
  readRegisters();             // Read the current register set
  if (volume < 0)  volume = 0;
  if (volume > 15) volume = 15;
  si4703_registers[SYSCONFIG2] &= 0xFFF0; // Clear volume bits
  si4703_registers[SYSCONFIG2] |= volume; // Set new volume
  updateRegisters();                      // Update the volume
  printRegisters("after volume set");
}

// --------------------------------------------------------------------
// Get the volume
// --------------------------------------------------------------------
int Si4703_Breakout::getVolume()
{
  readRegisters();          // Read the current register set
  uint16_t volume = si4703_registers[SYSCONFIG2];
  volume &= 0x000F;         // Clear other bits
  return (int)volume;
}

// --------------------------------------------------------------------
// Velleman subroutine for RDS
// --------------------------------------------------------------------
static inline void considerrdschar(char *buf, int place, char ch)
{
  if (ch < 0x10 || ch > 0x7F)
  {
    if (ch != 0x0D)
      return;
  }
  buf[place] = ch;
}

// --------------------------------------------------------------------
// Velleman subroutine for RDS
// --------------------------------------------------------------------
char Si4703_Breakout::CheckValidText(char* rt)
{
  char* endpos = strchr(rt, 0x0D);
  char* i = 0;
  char* previousSpacePos = rt;
  for (i = rt; i < endpos; i++)
  {
    if (*i == 0x20)
    {
      if (++previousSpacePos < i)
      {
        previousSpacePos = i;
      }
      else
      {
        return false;
      }
    }
  }
  return true;
}

// --------------------------------------------------------------------
// Listen for RDS data (Velleman version)
// --------------------------------------------------------------------
int Si4703_Breakout::readRDS(char* ps, char* rt)
{
  readRegisters();
  if (si4703_registers[STATUSRSSI] & (1 << RDSR)) {
    if (fakerds) {
      memset(rdsdata, 0, 8);
      rdschanged = 1;
    }

    fakerds = 0;

    //const uint16_t a = si4703_registers[RDSA];
    const uint16_t b = si4703_registers[RDSB];
    const uint16_t c = si4703_registers[RDSC];
    const uint16_t d = si4703_registers[RDSD];

    const uint8_t groupid = (b & 0xF000) >> 12;
    uint8_t version = b & 0x10;

    switch (groupid)
    {
      case RDS_PS:
        {
          const uint8_t index = (b & 0x3) * 2;
          char Dh = (d & 0xFF00) >> 8;
          char Dl = d;
          considerrdschar(rdsdata, index, Dh);
          considerrdschar(rdsdata, index + 1, Dl);
          rdschanged = 1;
        };
        break;
      case RDS_RT:
        {
          rdschanged = 1;
          uint8_t index = (b & 0xF) * 4;
          char Ch = (c & 0xFF00) >> 8;
          char Cl = c;
          char Dh = (d & 0xFF00) >> 8;
          char Dl = d;
          considerrdschar(radiotext, index, Ch);
          considerrdschar(radiotext, index + 1, Cl);
          considerrdschar(radiotext, index + 2, Dh);
          considerrdschar(radiotext, index + 3, Dl);
        };
        break;
    }
  }

  const int change = rdschanged;
  if (change)
  {
    strcpy(ps, rdsdata);
    strcpy(rt, radiotext);
  }
  rdschanged = 0;
  return (change) ? ((fakerds) ? (RDS_FAKE) : (RDS_AVAILABLE)) : (RDS_NO);
}


// --------------------------------------------------------------------
// To get the Si4703 inito 2-wire mode, SEN needs to be HIGH and SDIO needs to be LOW after a reset.
// The breakout board has SEN pulled high, but also has SDIO pulled high...
// Therefore, after a normal power up, the Si4703 will be in an unknown state. 
// RESET must be controlled.
// --------------------------------------------------------------------
void Si4703_Breakout::si4703_init()
{
  pinMode(_resetPin, OUTPUT);     // FM_RESET pin
  pinMode(_sdioPin, OUTPUT);      // SDIO (I2C)
  pinMode(_stcIntPin, OUTPUT);	  // STC (Search/Tune Complete) interrupt pin
  digitalWrite(_sdioPin, LOW);    // A low SDIO indicates a 2-wire interface
  digitalWrite(_resetPin, LOW);   // Put Si4703 into reset
  digitalWrite(_stcIntPin, HIGH); // STC will go low on interrupt
  delay(1);                       // Some delays while we allow pins to settle
  digitalWrite(_resetPin, HIGH);  // Bring Si4703 out of reset with SDIO set to low, and SEN pulled high with on-board resistor
  delay(1);                       // Allow Si4703 to come out of reset

  Serial.println(F(" Si4703 I2C initialization"));
  Wire.begin(); // Now that the unit is reset and I2C inteface mode, we need to begin I2C

  readRegisters();                   // Read the current register set
  //si4703_registers[0x07] = 0xBC04; // Enable the oscillator, from AN230 page 9, rev 0.5 (DOES NOT WORK, wtf Silicon Labs datasheet?)
  si4703_registers[0x07]  = 0x8100;  // Enable the oscillator, from AN230 page 9, rev 0.61 (works)
  si4703_registers[0x04] |= 0x2000;  // Set bit 14 to high to enable STC Interrupt on GPIO2
  updateRegisters();                 // Write the registers
  delay(500);                        // Wait for clock to settle - from AN230 page 9

  readRegisters();                             // Read the current register set
  si4703_registers[POWERCFG] = 0x4001;         // Enable the IC
  //si4703_registers[POWERCFG] |= (1<<SMUTE) | (1<<DMUTE); //Disable Mute, disable softmute
  si4703_registers[SYSCONFIG1] |= (1 << RDS);  // Enable RDS
  si4703_registers[SYSCONFIG1] |= (1 << DE);   // 50kHz Europe setup
  si4703_registers[SYSCONFIG2] |= (1 << SPACE0); // 100kHz channel spacing for Europe
  si4703_registers[SYSCONFIG2] &= 0xFFF0;      // Clear volume bits
  si4703_registers[SYSCONFIG2] |= 0x0001;      // Set volume to lowest
  updateRegisters();                           // Write the Registers
  delay(110);                                  // Max powerup time, from datasheet page 13
}

// --------------------------------------------------------------------
// Read the entire register control set, from 0x00 to 0x0F
// --------------------------------------------------------------------
void Si4703_Breakout::readRegisters()
{
  // Si4703 begins reading from register upper register of 0x0A and reads to 0x0F, then loops to 0x00.
  Wire.requestFrom(SI4703, 32); //We want to read the entire register set from 0x0A to 0x09 = 32 bytes.

  // Wait for 16 words/32 bytes to come back from slave I2C device
  int timeout = 100;          // with 100 ms timeout
  while ((Wire.available() < 32) && (timeout > 0))
  {
    delay(1);
    timeout--;
  }

  // Read the received data
  if (timeout == 0)
  { 
    Serial.println(F(" Warning: Si4703 I2C reception timeout"));
  }
  else
  {
    //Remember, register 0x0A comes in first so we have to shuffle the array around a bit
    for (int x = 0x0A ; ; x++)
    {
      // Read in these 32 bytes
      if (x == 0x10) x = 0; //Loop back to zero
      si4703_registers[x]  = Wire.read() << 8;
      si4703_registers[x] |= Wire.read();
      Serial.print("Si4703::readRegister("); Serial.print(x); Serial.print("): "); Serial.println(si4703_registers[x]);
      if (x == 0x09) break;                          //We're done!
    }
  }
}

// --------------------------------------------------------------------
//Write the current 9 control registers (0x02 to 0x07) to the Si4703
//It's a little weird, you don't write an I2C addres
//The Si4703 assumes you are writing to 0x02 first, then increments
// --------------------------------------------------------------------
byte Si4703_Breakout::updateRegisters()
{
  Wire.beginTransmission(SI4703);
  // A write command automatically begins with register 0x02 so no need to send a write-to address
  // First we send the 0x02 to 0x07 control registers.
  // In general, we should not write to registers 0x08 and 0x09.
  for (int regSpot = 0x02 ; regSpot < 0x08 ; regSpot++)
  {
    byte high_byte = si4703_registers[regSpot] >> 8;
    byte low_byte  = si4703_registers[regSpot] & 0x00FF;
    Wire.write(high_byte); // Upper 8 bits
    Wire.write(low_byte);  // Lower 8 bits
  }

  //End this transmission
  byte ack = Wire.endTransmission();
  if (ack != 0)
  {
    // 1: data too long to fit in transmit buffer
    // 2: received NACK on transmit of address
    // 3: received NACK on transmit of data
    // 4: other error
    Serial.print(F(" Warning: Si4703 I2C write failed with code ")); Serial.println(ack);
    return (FAIL);
  }
  else
  {
    // Serial.println(F("Si4703 Register write success"));
    return (SUCCESS);
  }
}

// --------------------------------------------------------------------
// Dump the Registers to the Serial output (debug purpose)
// --------------------------------------------------------------------
void Si4703_Breakout::printRegisters(String comment)
{
  Serial.println(comment);
  for (int regNo = 0x00 ; regNo < 0x0F ; regNo++)
  {
    uint16_t regValue = si4703_registers[regNo];
    Serial.print("Si4703 Register["); Serial.print(regNo); Serial.print("]: "); Serial.println(regValue);
  }
}


// --------------------------------------------------------------------
// Seeks out the next available station.
// Returns the frequency, if it made it.
// Returns zero if failed.
// --------------------------------------------------------------------
int Si4703_Breakout::seek(byte seekDirection)
{
  readRegisters();
  //Set seek mode wrap bit
  si4703_registers[POWERCFG] |= (1 << SKMODE); //Allow wrap
  //si4703_registers[POWERCFG] &= ~(1<<SKMODE); //Disallow wrap - if you disallow wrap, you may want to tune to 87.5 first
  if (seekDirection == SEEK_DOWN) si4703_registers[POWERCFG] &= ~(1 << SEEKUP); //Seek down is the default upon reset
  else si4703_registers[POWERCFG] |= 1 << SEEKUP; //Set the bit to seek up

  si4703_registers[POWERCFG] |= (1 << SEEK); //Start seek
  updateRegisters(); //Seeking will now start

  // Poll to see if STC is set
  while (1)
  {
    readRegisters();
    if ((si4703_registers[STATUSRSSI] & (1 << STC)) != 0) break; //Tuning complete!
  }

  readRegisters();
  int valueSFBL = si4703_registers[STATUSRSSI] & (1 << SFBL); //Store the value of SFBL
  si4703_registers[POWERCFG] &= ~(1 << SEEK); //Clear the seek bit after seek has completed
  updateRegisters();

  // Wait for the si4703 to clear the STC as well
  while (1)
  {
    readRegisters();
    if ( (si4703_registers[STATUSRSSI] & (1 << STC)) == 0) break; //Tuning complete!
  }

  if (valueSFBL)
  { // The bit was set indicating we hit a band limit or failed to find a station
    return (0);
  }
  // clear radiotext buffer on seek
  for (int i = 0; i < 65; i++)
  {
    radiotext[i] = 0;
  }
  return getChannel();
}
