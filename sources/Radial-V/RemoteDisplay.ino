// *******************************************************************************
// REMOTE DISPLAY
//
// Cet objet envoie des commandes a un écran TFT via un bus I2C.
// Il y a un autre arduino (slave) sur le bus I2C pour recevoir ces commandes
// *******************************************************************************

#include <Wire.h>
#include "RemoteDisplay.h"

// **********************************************************
// Contructor
// **********************************************************
RemoteDisplay::RemoteDisplay()
{}

// **********************************************************
// Initialise la connexion I2C en tant que Master.
// **********************************************************
void RemoteDisplay::begin()
{
  Wire.begin(); // join i2c bus (address optional for master)
}

// **********************************************************
// Demande d'effacer l'écran
// **********************************************************
void RemoteDisplay::clearBackground()
{
  Wire.beginTransmission(TFT_SLAVE);  // transmit to slave device
  Wire.write(C_CLEAR);                // sends one byte command
  Wire.endTransmission();             // stop transmitting
}

// **********************************************************
// Demande de charger l'image de fond
// **********************************************************
void RemoteDisplay::setBackgroundImage()
{
  Wire.beginTransmission(TFT_SLAVE);   // transmit to slave device
  Wire.write(C_BACKGROUNDIMAGE);       // sends one byte command
  Wire.endTransmission();              // stop transmitting
}
  
// **********************************************************
// Envoie un texte à afficher (Titre)
// Attention: la library Wire tronque à 32 chars.
// il faut donc envoyer en deux parties.
// **********************************************************
void RemoteDisplay::printTitle(String texte)
{
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
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_ICON0);                  // sends one byte command
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie une demande d'effacement des textes
// **********************************************************
void RemoteDisplay::clearAllText()
{
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  Wire.write(C_CLEARTEXT);              // sends one byte command
  Wire.endTransmission();               // stop transmitting
}

// **********************************************************
// Envoie une demande de picto
// **********************************************************
void RemoteDisplay::printPictoMute()
{
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
  Wire.beginTransmission(TFT_SLAVE);    // transmit to slave device 
  if (on)
    Wire.write(C_BLON);                 // sends one byte command
  else
    Wire.write(C_BLOFF);                // sends one byte command
  Wire.endTransmission();               // stop transmitting
}


// **********************************************************
// Demande de Status (1 byte)
// **********************************************************
char RemoteDisplay::requestStatus()
{
  char c;
  Wire.requestFrom(TFT_SLAVE, 1);
  while(Wire.available())    // slave may send less than requested
  { 
    c = Wire.read();    // receive a byte as character
  }
  return c;
}
