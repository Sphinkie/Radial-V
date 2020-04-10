/* ***********************************************************
 *  RADIO PLAYER
 *  
 *  Gestion de la carte Sparkfun FM player,
 *  Utilise la librairie "SparkFunSi4703" (qui utilise le bus I2C via la librarie <Wire.h>)
 * 
 ************************************************************* */
#include "RadioPlayer.h"


// ******************************************************************************
// Déclaration des objets (en dehors de la classe)
// ******************************************************************************


// ******************************************************************************
// Constructor
// ******************************************************************************
RadioPlayer::RadioPlayer(int pinRESET, int pinSDIO, int pinSCLK, int pinSTC) : Si4703_Breakout(pinRESET, pinSDIO, pinSCLK, pinSTC)
{
  // Le constructeur de la library mémorise juste les pins.
}


// ******************************************************************************
// Initialisation
// ******************************************************************************
void RadioPlayer::initialize()
{
  Serial.println(F("FM player initialization."));
  Si4703_Breakout::powerOn();   // Cette fonction initialise aussi le dialogue I2C. 
  // Attention, car Radial-V l'initialise aussi dans RemoteDisplay::begin()...
  volume=6;
  Si4703_Breakout::setVolume(volume);
  Serial.println(F(" FM player initialized."));
}

// ------------------------------------------------------------------
// Affiche les valeurs des variables de la classe
// ------------------------------------------------------------------
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
      this->listenRDSData();
    }
}


// ------------------------------------------------------------------
// Listen for RDS Data (15 sec timeout)
// ------------------------------------------------------------------
void RadioPlayer::listenRDSData()
{
      Serial.println(F("RDS listening"));
      Si4703_Breakout::readRDS(rdsBuffer, 15000);
      Serial.print(F("RDS heard:")); Serial.println(rdsBuffer);
}

// ------------------------------------------------------------------
// 
// ------------------------------------------------------------------
void RadioPlayer::setChannel(int channel_nb)
{
      Serial.print(F("set channel: ")); Serial.println(channel_nb);
      channel = channel_nb;
      //Si4703_Breakout::seekUp(); 
      Si4703_Breakout::setChannel(channel_nb);
      Serial.println("done");
      displayInfos();
}
