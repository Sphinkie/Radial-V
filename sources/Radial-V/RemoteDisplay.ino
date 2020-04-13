// *******************************************************************************
// REMOTE DISPLAY
//
// Cet objet envoie des commandes a un écran TFT via un bus I2C.
// Il y a un autre arduino (slave) sur le bus I2C pour recevoir ces commandes
// *******************************************************************************

#include <Wire.h>
#include "RemoteDisplay.h"

// **********************************************************
// Constructor
// **********************************************************
RemoteDisplay::RemoteDisplay()
{
   // Par defaut, on considère que l'Arduino Slave est connecté au bus I2C.
   this->I2Cconnected = true;
}

// **********************************************************
// Initialise la connexion I2C en tant que Master.
// **********************************************************
void RemoteDisplay::begin()
{
  Wire.begin(); // join i2c bus (no address for Master)
}

// **********************************************************
// Vérifie si le Slave est connecté au bus I2C
// Note: Aucune des deux méthodes testées n'est efficace.
// **********************************************************
bool RemoteDisplay::isSlavePresent()
{
   return this->I2Cconnected;
   /* ------------------------------------------
    *  Essai de différentes méthodes:
   // ------------------------------------------
   //   Methode 1: Request Status
   // ------------------------------------------
   char SlaveArduinoStatus = 0;
   SlaveArduinoStatus = this->requestStatus();
   return (SlaveArduinoStatus==0?false:true);       // return True if a STATUS is received
   // ------------------------------------------
   //   Methode 2: Simple Begin Transmission
   // ------------------------------------------
   int result;
   Wire.beginTransmission(TFT_SLAVE);   // transmit to slave device
   result = Wire.endTransmission();     // end transmission and store answer
   return (result==0?false:true);       // return True if ACK received
   // ------------------------------------------ */
}
void RemoteDisplay::setSlavePresent(bool present)
{
   this->I2Cconnected = present;
   Serial.print(F("Set I2C Slave: "));
   Serial.println(present?F("Present"):F("NOT Present"));
}

// **********************************************************
// Demande d'effacer l'écran
// **********************************************************
void RemoteDisplay::clearBackground()
{
  if (!I2Cconnected) return;
  Wire.beginTransmission(TFT_SLAVE);  // transmit to slave device
  Wire.write(C_CLEAR);                // sends one byte command
  Wire.endTransmission();             // stop transmitting
}

// **********************************************************
// Demande de charger l'image de fond
// **********************************************************
void RemoteDisplay::setBackgroundImage()
{
  if (!I2Cconnected) return;
  Wire.beginTransmission(TFT_SLAVE);   // transmit to slave device
  Wire.write(C_BACKGROUNDIMAGE);       // sends one byte command
  Wire.endTransmission();              // stop transmitting
}
  
// **********************************************************
// Envoie un texte à afficher (Titre)
// Notes: la library MP3 fournit un tag limité à 30 chars
//        la library Wire tronque à 32 chars.
// Donc le titre fourni par le MP3 doit tenir dans le message I2C à tous les coups.
// **********************************************************
void RemoteDisplay::printTitle(String texte)
{
  if (!I2Cconnected) return;
  Serial.print(F(" I2C Sending: "));  Serial.println (texte);
  
  if (texte.length()==0) texte= " ";

  // On envoie le titre
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_TITLE);                  // sends one byte command
  Wire.write(texte.c_str());            // sends string
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie un texte à afficher (Titre) en deux parties.
// Attention: la library Wire tronque à 32 chars.
// **********************************************************
void RemoteDisplay::printSplitedTitle(String texte)
{
  if (!I2Cconnected) return;
  Serial.print(F(" I2C Sending: "));  Serial.println (texte);
  int longeurTitre = texte.length();
  String TitrePart1 = "";
  String TitrePart2 = "";
  
  if (longeurTitre==0) texte= " ";

  if (longeurTitre > 23)
  {
    // le texte tient sur deux lignes: il faut trouver où tronquer.
    int cissure=longeurTitre;
    while (cissure>23)
    {
      cissure = texte.lastIndexOf(' ',cissure-1);
    }
    TitrePart1 = texte.substring(0,cissure);
    TitrePart2 = texte.substring(cissure+1);
  }
  else
  {
    TitrePart1 = texte;
    TitrePart2 = "\0";
  }

  // On envoie la première partie du titre
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_TITLE1);                 // sends one byte command
  Wire.write(TitrePart1.c_str());       // sends string
  Wire.endTransmission();               // stop transmitting

  // On envoie la seconde partie du titre
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_TITLE2);                 // sends one byte command
  Wire.write(TitrePart2.c_str());       // sends string
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie un texte à afficher (Artist)
// **********************************************************
void RemoteDisplay::printArtist(String texte)
{
  if (!I2Cconnected) return;
  if (texte.length()==0) texte= " ";
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_ARTIST);                 // sends one byte command
  Wire.write(texte.c_str());            // sends string
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie un texte à afficher (Album)
// **********************************************************
void RemoteDisplay::printAlbum(String texte)
{
  if (!I2Cconnected) return;
  if (texte.length()==0) texte= " ";
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_ALBUM);                  // sends one byte command
  Wire.write(texte.c_str());            // sends string
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie un texte à afficher (Year)
// **********************************************************
void RemoteDisplay::printYear(String texte)
{
  if (!I2Cconnected) return;
  if (texte.length()==0) texte= " ";
  if (texte=="0000"    ) texte= " ";
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_YEAR);                   // sends one byte command
  Wire.write(texte.c_str());            // sends string
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie un texte à afficher (Genre)
// **********************************************************
void RemoteDisplay::printGenre(String texte)
{
  if (!I2Cconnected) return;
  if (texte.length()==0) texte= " ";
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_GENRE);                  // sends one byte command
  Wire.write(texte.c_str());            // sends string
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie un texte à afficher (ligne de log)
// **********************************************************
void RemoteDisplay::printLog(String texte)
{
  if (!I2Cconnected) return;
  if (texte.length()==0) texte= " ";
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_LOG);                    // sends one byte command
  Wire.write(texte.c_str());            // sends string
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie le nombre d'étoiles à afficher (au format Ascii)
// **********************************************************
void RemoteDisplay::printStars(String texte)
{
  if (!I2Cconnected) return;
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_STARS);                  // sends one byte command
  Wire.write(texte[0]);                 // sends one char
  Wire.endTransmission();               // stop transmitting
}


// **********************************************************
// Envoie une demande d'effacement de picto
// **********************************************************
void RemoteDisplay::clearPicto()
{
  if (!I2Cconnected) return;
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_ICON0);                  // sends one byte command
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie une demande d'effacement des textes
// **********************************************************
void RemoteDisplay::clearAllText()
{
  if (!I2Cconnected) return;
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_CLEARTEXT);              // sends one byte command
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie une demande de picto
// **********************************************************
void RemoteDisplay::printPictoMute()
{
  if (!I2Cconnected) return;
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_ICON1);                  // sends one byte command
  Wire.write("i_MUTE");                 // sends string
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie une demande de picto
// **********************************************************
void RemoteDisplay::printPictoFM()
{
  if (!I2Cconnected) return;
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_ICON1);                  // sends one byte command
  Wire.write("i_FM");                   // sends string
  Wire.endTransmission();               // stop transmitting
}


// **********************************************************
// Allume ou éteint le rétro-éclairage
// **********************************************************
void RemoteDisplay::setBacklight(bool on)
{
  if (!I2Cconnected) return;
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  if (on)
    Wire.write(C_BLON);                 // sends one byte command
  else
    Wire.write(C_BLOFF);                // sends one byte command
  Wire.endTransmission();               // stop transmitting
}


// **********************************************************
// Demande de Status (1 byte) (0x01 = Ready)
// **********************************************************
char RemoteDisplay::requestStatus()
{
  char c=0;
  if (!I2Cconnected) return 0;
  Wire.requestFrom(TFT_SLAVE, 1);
  while(Wire.available())    // slave may send less than requested
  { 
    c = Wire.read();    // receive a byte as character
  }
  return c;
}
