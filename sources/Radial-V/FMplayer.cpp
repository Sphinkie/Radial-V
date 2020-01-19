/* ***********************************************************
 *  FM PLAYER
 *  
 *  Gestion de la carte Sparkfun FM player, en utilisant la 
 *  librairie "SparkFunSi4703" (qui utilise le bus I2C via la librarie <Wire.h>)
 *    
 ************************************************************* */

#include <SparkFunSi4703.h>   // Library pour shield FM Si7403
#include <Wire.h>             // Library pour bus I2C
#include "FMplayer.h"

int PIN_FM_RST = 2;     // RST* is used to reset the module (active LOW)
int PIN_STC = 3;        // Output Pin for the pulse indicating "Seek/Tune Completed"

// ---------------------------------------------------------------------
/*
 * Quelques pb: 
 * 
 *    FM_RST : la libraire a besoin d'une pin dédiée à la commande du RST du shield.... pas prévu.... peut-on en trouver une  de dispo ?
 *    STC    : ce pulse arrive de la pin GPI02 du ship... laquelle n'est pas cablée du tout!
 *    SEN    : Pas besoin de la cabler.
 *    STC : la librairie fait un traitement sous forme de wait until... serait-ce bloquant ? une interruption serait sans doute mieux.
 * 
 */

// ******************************************************************************
// Déclaration des objets (en dehors de la classe)
// ******************************************************************************
// Le constructeur de la library mémorise juste les pins.
Si4703_Breakout radio(FM_RESET, SDIO, SCLK, FM_STC);

// ------------------------------------------------------------------
// Constructor
// ------------------------------------------------------------------
FMplayer::FMplayer()
{
}

// ------------------------------------------------------------------
// Initialisation
// ------------------------------------------------------------------
void FMplayer::initialize()
{
  Serial.println(F("FM player initialization."));
  radio.powerOn();   // Cette fonction initialise aussi le dialogue I2C. 
  // Attention, car Radial-V l'initialise aussi dans RemoteDisplay::begin()...
  radio.setVolume(0);
  volume=0;
  Serial.println(F(" FM player initialized."));

}

// ------------------------------------------------------------------
//  Serial.println("a b     Favourite stations");
//  Serial.println("+ -     Volume (max 15)");
//  Serial.println("u d     Seek up / down");
//  Serial.println("r       Listen for RDS Data (15 sec timeout)");
// ------------------------------------------------------------------
void FMplayer::manage(char commande)
{
    if (commande == 'u') 
    {
      channel = radio.seekUp();
      displayInfo();
    } 
    else if (commande == 'd') 
    {
      channel = radio.seekDown();
      displayInfo();
    } 
    else if (commande == '+') 
    {
      volume ++;
      if (volume == 16) volume = 15;
      radio.setVolume(volume);
      displayInfo();
    } 
    else if (commande == '-') 
    {
      volume --;
      if (volume < 0) volume = 0;
      radio.setVolume(volume);
      displayInfo();
    } 
    else if (commande == 'a')
    {
      channel = 930; // Rock FM
      radio.setChannel(channel);
      displayInfo();
    }
    else if (commande == 'b')
    {
      channel = 974; // BBC R4
      radio.setChannel(channel);
      displayInfo();
    }
    else if (commande == 'r')
    {
      Serial.println("RDS listening");
      radio.readRDS(rdsBuffer, 15000);
      Serial.print("RDS heard:");
      Serial.println(rdsBuffer);      
    }
}

// ------------------------------------------------------------------
// ------------------------------------------------------------------
void FMplayer::displayInfo()
{
   Serial.print("Channel:"); Serial.print(channel); 
   Serial.print(" Volume:"); Serial.println(volume); 
}
