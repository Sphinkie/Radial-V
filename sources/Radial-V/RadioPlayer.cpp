/* *********************************************************************************************
     RADIO PLAYER

     Gestion de la carte Sparkfun FM player,
     Utilise la librairie "SparkFunSi4703" (qui utilise le bus I2C via la librarie <Wire.h>)
     Integration des fonctions de Velleman pour améliorer la gestion RDS.
 ******************************************************************************************** */
#include "RadioPlayer.h"

// ******************************************************************************
// Constructor (avec Classe de base = Si4703_Breakout)
// ******************************************************************************
RadioPlayer::RadioPlayer(int pinRESET, int pinSDIO, int pinSCLK, int pinSTC) : Si4703_Breakout(pinRESET, pinSDIO, pinSCLK, pinSTC)
{
  // Le constructeur de la library mémorise juste les pins.
  initStatus = FAIL;  // not ready
}

// ******************************************************************************
// Initialisation
// Cette fonction initialise aussi le dialogue I2C.
// Attention, à ne pas initialiser le bus I2C deux fois.
// ******************************************************************************
void RadioPlayer::initialize()
{
  Serial.println(F("FM player initialization."));
  initStatus = Si4703_Breakout::init();   // Cette fonction initialise aussi le dialogue I2C.
  if (initStatus==SUCCESS)
    Serial.println(F(" done."));
  else
    Serial.println(F(" failed."));
  
}

// ******************************************************************************
// Renvoie True si on a réussi à initialiser la carte Si4703
// ******************************************************************************
bool RadioPlayer::isReady()
{
  return (initStatus==SUCCESS);
}

// ******************************************************************************
// Affiche les valeurs des variables de la classe
// ******************************************************************************
void RadioPlayer::displayInfos()
{
  Serial.print(F("Channel:")); Serial.print(this->channel);
  Serial.print(F(" Volume:")); Serial.println(this->volume);
}

// ------------------------------------------------------------------
//  a b  :   Favourite stations
//  + -  :   Volume (max 15)
//  u d  :   Seek up/down
//  r    :   Listen for RDS Data
// ------------------------------------------------------------------
void RadioPlayer::manageRadio(char commande)
{
  char rdsname[9];
  char rdsrt[65];
  uint8_t lastChar;

  Serial.print(F(" commande: ")); Serial.println(commande);
  if (commande == 'u')
  {
    channel = Si4703_Breakout::seekUp();
    displayInfos();
  }
  else if (commande == 'd')
  {
    channel = Si4703_Breakout::seekDown();
    displayInfos();
  }
  else if (commande == '+')
  {
    volume ++;
    if (volume > 15) volume = 15;
    Si4703_Breakout::setVolume(volume);
    displayInfos();
  }
  else if (commande == '-')
  {
    volume --;
    if (volume < 0) volume = 0;
    Si4703_Breakout::setVolume(volume);
    displayInfos();
  }
  else if (commande == 'a')
  {
    channel = 930;    // RockFM  90.3 MHz
    Si4703_Breakout::setChannel(channel);
    displayInfos();
  }
  else if (commande == 'b')
  {
    this->setChannel(974);      // BBC  97.4 MHz
  }
  else if (commande == 'r')
  {
    // The calling of readRDS and printing of rdsname really need to be looped to catch all of the data...
    // This will just print a snapshot of what is in the Si4703 RDS buffer...
    this->readRDSRadioStation(rdsname);
    Serial.println(rdsname);
  }
  else if (commande == 'R')
  {
    // The calling of readRDS and printing of rdsrt really need to be looped to catch all of the data...
    // This will just print a snapshot of what is in the Si4703 RDS buffer...
    this->readRDS(rdsname, rdsrt, &lastChar);
    Serial.println(rdsrt);
  }
}


// ------------------------------------------------------------------
// Change la frequence sélectionnée
// ------------------------------------------------------------------
void RadioPlayer::setChannel(int channel_nb)
{
  Serial.print(F("set channel: ")); Serial.println(channel_nb);
  channel = channel_nb;
  Si4703_Breakout::setChannel(channel_nb);
  Serial.println("done");
  displayInfos();
}


// ------------------------------------------------------------------
// Velleman RDS variables
// ------------------------------------------------------------------
int ReadRDSState = 0;
#define CLEARBUFFER 0
#define READUNTILEOL 1
#define READUNTILBEGIN 2
#define READUNTILEND 3
uint8_t position = 0;
char poststation[9];

// ------------------------------------------------------------------
// Velleman : lecture du nom RDS de la station
// ------------------------------------------------------------------
char RadioPlayer::readRDSRadioStation(char* rs)
{
  strcpy(rs, poststation);
}

// ------------------------------------------------------------------
// Velleman : lecture des infos RDS de l'émission
// ------------------------------------------------------------------
char RadioPlayer::readRDSRadioText(char* rt)
{
  memset(poststation, 0, 9);
  char status = 0;
  switch (ReadRDSState)
  {
    case CLEARBUFFER:
      memset(rt, 0, 65);
      memset(radiotext, 0, 65);
      ReadRDSState++;
      break;
    case READUNTILEOL:
      //When no CR(Carriage Return) is found => read RDS
      if (strchr(rt, 0x0D) == 0)
      {
        readRDS(poststation, rt, &position);
      }
      else
      {
        memset(rt, 0, 65);
        memset(radiotext, 0, 65);
        ReadRDSState++;
        position = 100;
      }
      break;
    case READUNTILBEGIN:
      if (position)
      {
        readRDS(poststation, rt, &position);
      }
      else
      {
        ReadRDSState++;
        position = 100;
        memset(rt, 0, 65);
        memset(radiotext, 0, 65);
      }
      break;
    case READUNTILEND:
      if (strchr(rt, 0x0D) == 0)
      {
        readRDS(poststation, rt, &position);
      }
      else
      {
        if (CheckValidText(rt))
        {
          status = 1; //Text found
          ReadRDSState = 0;
        }
      }
      break;
    default:
      break;
  }
  return status;
}

// ------------------------------------------------------------------
// Vellemean RDS subroutine
// ------------------------------------------------------------------
static inline void considerrdschar(char *buf, int place, char ch)
{
  if (ch < 0x10 || ch > 0x7F)
  {
    if (ch != 0x0D)
      return;
  }
  buf[place] = ch;
}

// ------------------------------------------------------------------
// Velleman: Surcharge de la lecture RDS.
// Légère variante de la fonction de la classe de base.
// ------------------------------------------------------------------
int RadioPlayer::readRDS(char* ps, char* rt, uint8_t* pos)
{
  readRegisters();
  if (si4703_registers[STATUSRSSI] & (1 << RDSR))
  {
    if (fakerds)
    {
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
          *pos = index;
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
