/* ************************************************************************************************
 *
 *   RADIAL-SCREEN
 *
 * Software pour la radio Radial-V.
 *
 * Pilotage par Arduino-MEGA d'un ecran TFT
 *
 *************************************************************************************************** 
 * 03/11/2015    Creation
 * 16/11/2015    Ensemble des commandes I2C. Elements graphiques 
 * 02/01/2020    Modification de cablage. Ajout de la commande I2C "CTITLE2"
 *************************************************************************************************** */

#include <Wire.h>     // Librairie Arduino pour le bus I2C
#include "RadialScreen.h"
#include "ArrayQueue.h"
#include "Display.h"


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
  LCDdisplay.setBackgroundColor(BG_R,BG_G,BG_B);
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
  
  delay(40);    // 40 ms = 1 frame = 25 par secondes

  // -----------------------------------------------------------------------
  // Si le bus I2C est Ready, on traite les messages reçus
  // -----------------------------------------------------------------------
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
      case C_TITLE    : LCDdisplay.printScrollingTitle(Data);  break;
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
      case C_ICON1    : LCDdisplay.showPicto(Data, 40, 20); break;    // Image size: 80x80
      case C_ICON2    : LCDdisplay.showPicto("i_AUDIO",40, 20); break;
      case C_STARS : {
                      if      (Data[0]<'0') LCDdisplay.clearStars();
                      else if (Data[0]>'5') LCDdisplay.clearStars();
                      else                  LCDdisplay.printStars(Data[0]-'0');        
                      break;
                     }
      // Autres commandes
      case C_BACKGROUNDIMAGE : LCDdisplay.setBackgroundImage("bg_RADV.bmp"); break;
      case C_CLEAR           : LCDdisplay.setBackgroundColor(BG_R,BG_G,BG_B);break;
      case C_BLON            : LCDdisplay.setBacklight(255);                 break;  
      case C_BLOFF           : LCDdisplay.setBacklight(0);                   break;
      case C_ASCII           : LCDdisplay.printAllChars();                   break;  
      // Autres cas  
      default      : 
          LCDdisplay.showPicto("i_AUDIO",40, 20);
          LCDdisplay.printLog("Unknown I2C command");             
          break;
      }
    }
  }
  
  // -----------------------------------------------------------------------
  // Si nécessaire, on fait scroller le texte déroulant.
  // -----------------------------------------------------------------------
  if (LCDdisplay.isScrolling)
  {
    LCDdisplay.scrollTitle();
  }

  bool debug = true;
  // -----------------------------------------------------------------------
  // Si debug, on écoute le port série, pour recevoir des commandes .
  //   a-z-e : augmente les valeurs rgb
  //   q-s-d : augmente les valeurs rgb
  // -----------------------------------------------------------------------
  if (debug)
  {
    int commande = 0;
    commande = Serial.read();
    // if (commande >0) {Serial.print("Received: "); Serial.println(commande, DEC);}
    switch (commande)
    {
      case 'a':
        LCDdisplay.adjustBackgroundColor(1,0,0);
        break;
    case 'q':
        LCDdisplay.adjustBackgroundColor(-1,0,0);
        break;
    case 'z': 
        LCDdisplay.adjustBackgroundColor(0,1,0);
        break;
    case 's': 
        LCDdisplay.adjustBackgroundColor(0,-1,0);
        break;
    case 'e': 
        LCDdisplay.adjustBackgroundColor(0,0,1);
        break;
    case 'd': 
        LCDdisplay.adjustBackgroundColor(0,0,-1);
        break;
    case 10:  // envoi 
        LCDdisplay.setBackground();
        break;
    }
  } 
}



// *******************************************************************************
// Function executed when some DATA is received from master.
// This function is registered as an event.
// *******************************************************************************
void receiveEvent(int howMany)
{
  Serial.print(F("I2C data received "));
  // Le premier octet est une commande
  int   Command = Wire.read();  // receive byte as a integer
  Serial.print("[");  Serial.print(Command);  Serial.print("]: ");
  // Ensuite, on a les Data
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
  char Status = Ready? 1: 0;
  Wire.write(Ready);                 // 0x01 = READY
  Serial.println(F("I2C request received"));
}
