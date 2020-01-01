/* ************************************************************************************************

    RADIAL-SCREEN

Software pour la radio Radial-V.

Pilotage par Arduino-MEGA d'un ecran TFT

*************************************************************************************************** 
* 1.0     03/11/2015    Creation
*************************************************************************************************** 
* 1.1     16/11/2015    Ensemble des commandes I2C
*                       Elements graphiques 
*************************************************************************************************** 
*/

#include <Wire.h>     // Librairie Arduino pour le bus I2C

#include "Display.h"
#include "RadialScreen.h"
#include "ArrayQueue.h"

// *******************************************************************************
// Cablage
// *******************************************************************************
#define BACKLIGHT 23  // PWM
#define RESET     25  // Reset du TFT
#define DC_LD     27  // Data/Command du TFT
#define CS_SD     29  // SPI Slave Select pour SD
#define CS_LD     31  // SPI Slave Select pour ecran TFT
#define MOSI      51  // SPI MOSI pour UNO or ICSP-4 (51 sur MEGA) (11 sur UNO)
#define MISO      50  // SPI MISO pour UNO or ICSP-1 (50 sur MEGA) (12 sur UNO)
#define SCK       52  // SPI SCK  pour UNO or ICSP-3 (52 sur MEGA) (13 sur UNO)
#define SS_SLAVE  53  // SPI Slave Select pour UNO   (53 sur MEGA) (10 sur UNO) Non utilisé ici car Arduino est MASTER

bool              Ready = false;
Display           LCDdisplay;
ArrayQueue        Fifo;

// *******************************************************************************
// The setup function runs once when you press reset or power the board
// *******************************************************************************
void setup() 
{
  // On initialise les pinoches de sorties au niveau haut.
  pinMode(SS_SLAVE, OUTPUT);    digitalWrite(SS_SLAVE, HIGH);   
  pinMode(CS_SD,    OUTPUT);    digitalWrite(CS_SD,    HIGH);   
  pinMode(CS_LD,    OUTPUT);    digitalWrite(CS_LD,    HIGH);   

  // Initialisation de la RS de debug
  Serial.begin(115200);
  
  Serial.println(F("-----------------------------------"));
  Serial.println(F("--   RADIAL SCREEN               --"));
  Serial.println(F("-----------------------------------"));

  Serial.print  (F("CPU Frequency: ")); Serial.print(F_CPU/1000000);  Serial.println(F(" MHz"));
  Serial.print  (F("Free RAM: "));      Serial.print(FreeRam(), DEC); Serial.println(F(" bytes"));   // FreeRam is provided by SdFatUtil.h
  Serial.println(F("-----------------------------------"));

  // Initialisation de la connection au bus IIC
  Wire.begin(TFT_SLAVE);                // join i2c bus with address 0x02
  Wire.onReceive(receiveEvent);         // register an event called then receiving a transmission from master
  Wire.onRequest(requestEvent);         // register an event called then receiving a request from master
  Serial.println(F("I2C initialization........done"));
  
  // Initialisation de l'écran TFT
  LCDdisplay.initDisplay();
  LCDdisplay.setBackground(BG_R,BG_G,BG_B);
  // LCDdisplay.printLog(F("  Radial-V demarrage."));
  Serial.println(F("LCD initialization........done"));

  LCDdisplay.setBackgroundImage("bg_RADV.bmp");
  LCDdisplay.setBacklight(0);                   // TFT Backlight OFF

  Ready = true;
  Serial.println(F("-----------------------------------"));

}


// *******************************************************************************
// The loop function runs over and over again forever
// *******************************************************************************
void loop() 
{
  int     Command;
  String  Data;
  
  delay(500);

  if (Ready) 
  {
  // A-t-on reçu une commande récemment? On consulte la FIFO...
  if (!Fifo.isEmpty())  
    {
    // Si oui, on lit la commande recue
    Command = Fifo.deQueue();
    // Serial.print ("deQueue Command: ");Serial.println (Command);
    // On recupère les Data associées à la commande
    Data = Fifo.getData(Command);
    // Serial.print (" deQueue Data: ");Serial.println (Data);
    // On traite la commande
    switch (Command)
      {
      // affichage des champs textuels
      case C_TITLE1   : LCDdisplay.printTitle(1,Data);      break;
      case C_TITLE2   : LCDdisplay.printTitle(2,Data);      break;
      case C_ARTIST   : LCDdisplay.printArtist(Data);       break;
      case C_ALBUM    : LCDdisplay.printAlbum(Data);        break;
      case C_YEAR     : LCDdisplay.printYear(Data);         break;
      case C_GENRE    : LCDdisplay.printGenre(Data);        break;
      case C_LOG      : LCDdisplay.printLog(Data);          break;
      case C_CLEARTEXT: LCDdisplay.clearAllTexts();         break;
      // Affichage des pictos
      case C_ICON0    : LCDdisplay.clearPicto();            break;
      case C_ICON1    : LCDdisplay.showPicto(Data, 25, 14); break;    // Image size: 77x79
      case C_ICON2    : LCDdisplay.showPicto("bg_TATOO",0, 0); break;
      case C_STARS : {
                      if      (Data[0]<'0') LCDdisplay.clearStars();
                      else if (Data[0]>'5') LCDdisplay.clearStars();
                      else                  LCDdisplay.printStars(Data[0]-'0');        
                      break;
                     }
      // Autres commandes
      case C_BACKGROUNDIMAGE : LCDdisplay.setBackgroundImage("bg_RADV.bmp"); break;
      case C_CLEAR           : LCDdisplay.setBackground(BG_R,BG_G,BG_B);     break;
      case C_BLON            : LCDdisplay.setBacklight(255);                 break;  
      case C_BLOFF           : LCDdisplay.setBacklight(0);                   break;
      case C_ASCII           : LCDdisplay.printAllChars();                   break;  
      // Autres cas  
      default      : LCDdisplay.printLog("Unknown I2C command");             break;
      }
    }
  }
}



// *******************************************************************************
// Function executed when some DATA is received from master.
// This function is registered as an event.
// *******************************************************************************
void receiveEvent(int howMany)
{
  Serial.print(F("I2C data received: "));
  // Le premier octet est une commande
  int   Command = Wire.read();  // receive byte as a integer
  char  Data[howMany];
  int   i=0;

  // Les octets suivants sont un texte (au format char*)
  while (Wire.available()>0)  // loop through all bytes
  {
    char x = Wire.read();     // receive byte as an character
    Data[i++]=x;
  }
  Data[i]='\0'; // fin de chaine
  Serial.println(Data);

  // On stocke les info reçues dans la fifo.
  Fifo.enQueue(Command, Data);
}


// *******************************************************************************
// Function executed when a REQUEST is received from master.
// This function is registered as an event.
// *******************************************************************************
void requestEvent()
{
  // Le Master attend 1 octet. On envoie notre status: "Ready".
  Wire.write(1);                 // 0x01 = READY
  Serial.println(F("I2C request received"));
}
