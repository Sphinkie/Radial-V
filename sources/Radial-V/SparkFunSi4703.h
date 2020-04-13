/* 
 * ----------------------------------------------------------------------------------------------------------------------------------
 * Library for Sparkfun Si4703 breakout board.
 *
 * Notes:
 *   - The Si4703 ACKs the first byte, and NACKs the 2nd byte of a read.
 *   - I suggest NEVER write to a register without first reading the contents of a chip. ie, don't updateRegisters without first readRegisters.
 *   - The Si4703 breakout does work with line out into a stereo or other amplifier. 
 *     Be sure to test with different length 3.5mm cables. Too short of a cable may degrade reception.
 * ----------------------------------------------------------------------------------------------------------------------------------
 */

#ifndef SparkFunSi4703_h
#define SparkFunSi4703_h

#include "Arduino.h"

#define RDS_NO (0)
#define RDS_FAKE (1)
#define RDS_AVAILABLE (2)


class Si4703_Breakout
{
  public:
    Si4703_Breakout(int resetPin, int sdioPin, int sclkPin, int stcIntPin);
    void powerOn();				        // call in setup
	  void setChannel(int freq);  	// frequency in 100 kHz (europe: 875..1050)
	  int  seekUp(); 					      // returns the tuned channel or 0
	  int  seekDown(); 				
    void setVolume(int volume);     // 0 to 15
    int  getVolume();
	  char readRDSRadioText(char* rt);
	  int  readRDS(char* ps, char* rt);

  protected:
    // RDS specific stuff
    #define RDS_PS (0)
    #define RDS_RT (2)
    int rdschanged = 0;
    int fakerds = 0;
    uint8_t previousversion =0;
    // RDS buffering
    char rdsdata[9];
    char radiotext[65];
    // pins
    int  _resetPin;
	  int  _sdioPin;
	  int  _sclkPin;
	  int  _stcIntPin;

    // protected functions
	  void si4703_init();
	  void readRegisters();
    void printRegisters(String comment);
    byte updateRegisters();
	  int  seek(byte seekDirection);
	  int  getChannel();
    char CheckValidText(char* rt);
    
	  uint16_t si4703_registers[16]; //There are 16 registers, each 16 bits large
	  static const uint16_t  FAIL = 0;
	  static const uint16_t  SUCCESS = 1;

	  static const int       SI4703 = 0x10;     // _001.0000 = I2C address of Si4703 - Note that the Wire function assumes non-left-shifted I2C address, not 0010.000W
	  static const uint16_t  I2C_FAIL_MAX = 10; // This is the number of attempts we will try to contact the device before erroring out
	  static const uint16_t  SEEK_DOWN = 0;     // Direction used for seeking. Default is down
	  static const uint16_t  SEEK_UP = 1;

	  // Define the Register names
	  static const uint16_t  DEVICEID   = 0x00;
	  static const uint16_t  CHIPID     = 0x01;
	  static const uint16_t  POWERCFG   = 0x02;
	  static const uint16_t  CHANNEL    = 0x03;
	  static const uint16_t  SYSCONFIG1 = 0x04;
	  static const uint16_t  SYSCONFIG2 = 0x05;
	  static const uint16_t  STATUSRSSI = 0x0A;
	  static const uint16_t  READCHAN   = 0x0B;
	  static const uint16_t  RDSA       = 0x0C;
	  static const uint16_t  RDSB       = 0x0D;
	  static const uint16_t  RDSC       = 0x0E;
	  static const uint16_t  RDSD       = 0x0F;

	  // Register 0x02 - POWERCFG
	  static const uint16_t  SMUTE  = 15;
	  static const uint16_t  DMUTE  = 14;
	  static const uint16_t  SKMODE = 10;
	  static const uint16_t  SEEKUP = 9;
	  static const uint16_t  SEEK   = 8;

	  // Register 0x03 - CHANNEL
	  static const uint16_t  TUNE = 15;
  
	  // Register 0x04 - SYSCONFIG1
	  static const uint16_t  RDS = 12;
	  static const uint16_t  DE  = 11;
  
	  // Register 0x05 - SYSCONFIG2
	  static const uint16_t  SPACE1 = 5;
	  static const uint16_t  SPACE0 = 4;

	  // Register 0x0A - STATUSRSSI
	  static const uint16_t  RDSR   = 15;
	  static const uint16_t  STC    = 14;
	  static const uint16_t  SFBL   = 13;
	  static const uint16_t  AFCRL  = 12;
	  static const uint16_t  RDSS   = 11;
	  static const uint16_t  STEREO = 8;
};

#endif
