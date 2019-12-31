/* ************************************************************************************************

Librairie pour piloter le shield ARDUINO ROBOT LCD SCREEN

Utilise les librairies Arduino suivantes:
- SD    pour les accès à la carte SD du shield "Arduino Screen"
- TFT   pour les accès à l'écran LCD du shield "Arduino Screen"
- SPI   pour le bus SPI   (inutile: a été enlevé)

*************************************************************************************************** 
* 1.0     03/11/2015    Creation
*************************************************************************************************** 
*************************************************************************************************** 
*/

#include <SD.h>
#include <TFT.h>  
#include "display.h"
#include "Unicode.h"

// On instancie la librairie TFT avec les pin utilisés
TFT     TFTscreen(CS_LD,DC_LD,RESET);


// **********************************************************
// Contructor
// **********************************************************
Display::Display() 
{
  strcpy(CurrentTitle1, "");
  strcpy(CurrentTitle2, "");
  strcpy(CurrentAlbum,  "");
  strcpy(CurrentArtist, "");
  strcpy(CurrentYear,   "");
  strcpy(CurrentGenre,  "");
  strcpy(CurrentLog,    "");

  pinMode(BACKLIGHT, OUTPUT);    
  this->setBacklight(0);     // lum. faible
}

// **********************************************************
// Initialise l'affichage
// **********************************************************
void Display::initDisplay() 
{
  // Initialisation de la carte SD. En car d'erreur, le programme stoppe.
  Serial.print(F("Initializing TFT SD card..."));
  if (!SD.begin(CS_SD)) 
  {
    Serial.println(F("failed!"));
    return;
  }
  Serial.println(F("OK!"));

  StarOn  = TFTscreen.loadImage("star_f.bmp");
  StarOff = TFTscreen.loadImage("star_e.bmp");

  // Put this line at the beginning of every sketch that uses the LCD:
  TFTscreen.begin();
  TFTscreen.background(0, 0, 0);               // clear the screen with black
  TFTscreen.setTextSize(1);                    // set the font size to 1
}

// **********************************************************
// Efface l'écran et mémorise la couleur de fond
// **********************************************************
void Display::setBackground(int R, int G, int B) 
{
  TFTscreen.background(R, G, B);            // clear the screen with a rgb background
  BackgroundR = R;
  BackgroundG = G;
  BackgroundB = B;

  strcpy(CurrentTitle1,"");
  strcpy(CurrentTitle2,"");
  strcpy(CurrentAlbum, "");
  strcpy(CurrentArtist,"");
  strcpy(CurrentYear,  "");
  strcpy(CurrentGenre, "");
  strcpy(CurrentLog,   "");
}

// **********************************************************
// Efface un texte
// **********************************************************
void Display::eraseText(char* texte, int X, int Y) 
{
  TFTscreen.stroke(BackgroundR, BackgroundG, BackgroundB);
  TFTscreen.text(texte, X, Y);
}

// **********************************************************
// Affiche un titre (sur deux lignes)
// **********************************************************
void Display::printTitle(String texte) 
{
  // On efface le texte précédent
  this->clearField(X_MARGIN,Y_TITLE,24*5,8);
  this->clearField(X_MARGIN,Y_TITLE+10,24*5,8);
  strcpy(CurrentTitle1, "");
  strcpy(CurrentTitle2, "");

  if (texte.length()>21)
  {
    // le texte tient sur deux lignes: il faut trouver où tronquer.
    int cissure=texte.length();
    while (cissure>21)
    {
      cissure = texte.lastIndexOf(' ',cissure-1);
    }
    this->cleanString(texte.substring(0,cissure), CurrentTitle1);
    this->cleanString(texte.substring(cissure+1), CurrentTitle2);
  }
  else
  {
    this->cleanString(texte,CurrentTitle1);
    Serial.println(CurrentTitle1);
  }
  // Serial.println(CurrentTitle1);
  // Serial.println(CurrentTitle2);

  // On écrit les deux lignes
  TFTscreen.setTextSize(1);              
  //TFTscreen.setTextWrap(true);                       // Cette fonction est héritée de la library Adafruit GFX, mais sans effet notable ici.
  TFTscreen.stroke(DARK_R, DARK_G, DARK_B);            // set the font color
  TFTscreen.text(CurrentTitle1, X_MARGIN, Y_TITLE);    // print the text at X,Y
  TFTscreen.text(CurrentTitle2, X_MARGIN, Y_TITLE+10); // print the text at X,Y
  
}

// **********************************************************
// Affiche le nom de l'artiste
// **********************************************************
void Display::printArtist(String texte) 
{
  texte.remove(21);                                     // On tronque le texte à 21 chars.
  if (texte.length()<18) texte="par "+texte;            // Si la longueur le permet, on rajoute "par"
  this->clearField(X_MARGIN, Y_ARTIST, 24*5, 8);
  this->cleanString(texte, CurrentArtist);              // On copie le texte dans CurrentArtist
  TFTscreen.setTextSize(1);
  TFTscreen.stroke(GREYED_R, GREYED_G, GREYED_B);       // set the font color
  TFTscreen.text(CurrentArtist, X_MARGIN, Y_ARTIST);    // print the text at X,Y
}

// **********************************************************
// Affiche le nom de l'Album
// **********************************************************
void Display::printAlbum(String texte) 
{
  texte.remove(19);                                    // On tronque le texte à 19 chars.
  texte='"'+texte+'"';
  this->clearField(X_MARGIN, Y_ALBUM, 24*5, 8);
  this->cleanString(texte, CurrentAlbum);             // On copie le texte dans CurrentAlbum
  TFTscreen.setTextSize(1);
  TFTscreen.stroke(GREYED_R, GREYED_G, GREYED_B);     // set the font color
  TFTscreen.text(CurrentAlbum, X_MARGIN, Y_ALBUM);    // print the text at X,Y
}


// **********************************************************
// Affiche l'année
// **********************************************************
void Display::printYear(String texte) 
{
  //this->eraseText(CurrentYear,X_YEAR, Y_YEAR);
  this->clearField(X_YEAR,Y_YEAR,5*5,8);
  this->cleanString(texte, CurrentYear);        // On copie le texte dans CurrentYear
  TFTscreen.setTextSize(1);
  TFTscreen.stroke(DARK_R, DARK_G, DARK_B);     // set the font color
  TFTscreen.text(CurrentYear, X_YEAR, Y_YEAR);  // print the text at X,Y
}


// **********************************************************
// Affiche le Genre.
// **********************************************************
void Display::printGenre(String texte) 
{
  texte.remove(11);                                    // On tronque le genre à 11 chars.
  this->clearField(X_GENRE, Y_GENRE, 11*5, 8);
  this->cleanString(texte, CurrentGenre);              // On copie le texte dans CurrentGenre
  TFTscreen.setTextSize(1);
  TFTscreen.stroke(DARK_R, DARK_G, DARK_B);            // set the font color
  TFTscreen.text(CurrentGenre, X_GENRE, Y_GENRE);      // print the text at X,Y
}

// **********************************************************
// Afiche le nombre d'étoiles demandées 
// **********************************************************
void Display::printStars(int number)
{
  int i;
  if (number>5) number=5;
  
  for (byte i=0; i<number; i++)
  {
    TFTscreen.image(StarOn, X_STARS+i*24, Y_STARS);
  }
  for (byte i=number; i<5; i++)
  {
    TFTscreen.image(StarOff, X_STARS+i*24, Y_STARS);
  }
}

    
// **********************************************************
// Affiche une ligne de log en rouge en bas de l'écran
// **********************************************************
void Display::printLog(String  texte) 
{
  texte.remove(21);                               // On tronque le texte à 21 chars.
  this->clearField(X_MARGIN,Y_TRACE,24*5,8);
  this->cleanString(texte, CurrentLog);           // On copie le texte dans CurrentLog
  TFTscreen.setTextSize(1);
  TFTscreen.stroke(200, 20, 20);                  // Couleur Rouge
  TFTscreen.text(CurrentLog, X_MARGIN, Y_TRACE);  // Print the text at X,Y
}


// **********************************************************
// Affiche une image de fond
// **********************************************************
void Display::setBackgroundImage(char* filename)
{
  // draw the image to the screen
  BackgroundImage = TFTscreen.loadImage(filename); //.c_str());   // on convertit le String en Char Array
  if (!BackgroundImage.isValid()) Serial.println(F("error while loading background image"));
  TFTscreen.image(BackgroundImage, 0, 0);
}

// ******************************************************************************
// Efface les étoiles
// ******************************************************************************
void Display::clearStars()
{
  TFTscreen.stroke(BackgroundR, BackgroundG, BackgroundB);
  TFTscreen.fill(BackgroundR, BackgroundG, BackgroundB);
  TFTscreen.rect(X_STARS,Y_STARS,5*24,24);
}

// ******************************************************************************
// Efface tous les textes par deux rectangles
// ******************************************************************************
void Display::clearAllTexts()
{
  TFTscreen.stroke(BackgroundR, BackgroundG, BackgroundB);
  TFTscreen.fill(BackgroundR, BackgroundG, BackgroundB);
  TFTscreen.rect(X_YEAR,  Y_YEAR ,16*5,30);    
  TFTscreen.rect(X_MARGIN,Y_TITLE,24*5,52);  
}

// ******************************************************************************
// Affiche le contenu de la carte SD
// ******************************************************************************
void Display::ls()
{
  File root;

  Serial.println(F("Files found (name date size):"));
  root = SD.open("/");
  printDirectory(root, 0);
}


// ******************************************************************************
// Fonction recursive pour l'affichage du contenu d'un repertoire de la carte SD
// ******************************************************************************
void Display::printDirectory(File dir, int numTabs) 
{
   while (true) 
   {
     File entry =  dir.openNextFile();
     if (! entry) {break;} // no more files
      
     for (uint8_t i = 0; i < numTabs; i++) {Serial.print('\t');}
     Serial.print(entry.name());
     if (entry.isDirectory()) 
     {
       Serial.println("/");
       printDirectory(entry, numTabs + 1);
     } 
     else 
     {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
    entry.close();
  }
}


// ******************************************************************************
// Reglage du niveau de rétro éclairage du TFT
// 255 = lumineux
// 0 = faible
// ******************************************************************************
void Display::setBacklight(int value)
{
    analogWrite(BACKLIGHT, 255-value);    // pour le TFT, 0 est allumé
}


// ******************************************************************************
// Affichage d'un picto (BMP file)
// ******************************************************************************
void Display::showPicto(String filename, int x, int y)
{
  if (filename.length()==0) return clearPicto();
  
  filename = filename+".bmp";
  Serial.print(F(" showPicto ")); Serial.println(filename);
  // draw the image to the screen
  Picto = TFTscreen.loadImage(filename.c_str());
  if (!Picto.isValid()) Serial.println(F("error while loading Picto"));
  TFTscreen.image(Picto, x, y);
  PictoX = x;
  PictoY = y;
  PictoW = Picto.width();
  PictoH = Picto.height();
}


// ******************************************************************************
// Effacement du picto précédent
// ******************************************************************************
void Display::clearPicto()
{
clearAllTexts();

/*  Serial.println(F(" clearPicto")); 
  TFTscreen.stroke(BackgroundR, BackgroundG, BackgroundB);
  TFTscreen.fill  (BackgroundR, BackgroundG, BackgroundB);
  TFTscreen.rect(PictoX,PictoY,PictoW,PictoH);
  */
}


// ******************************************************************************
// Enlève les accents et transforme le String en Char array
// Attn: texteOUT est une variable de sortie!
// Attn: le Genre est en UTF-8 sur 2 chars, et pas en Unicode. 
// ******************************************************************************
void Display::cleanString(String texteIN, char* texteOUT) 
{
  unsigned int lettre;
  unsigned int UTF8prefix = 0xFFC3;
  byte indexOUT = 0;
  bool isUTF8 = false;
  
  Serial.print("cleanString:"); 
  for (byte indexIN=0; indexIN<texteIN.length()+1; indexIN++) 
  {
    lettre = int(texteIN[indexIN]); 
    Serial.print(" 0x"); Serial.print(lettre,HEX);
    
    if (isUTF8)
    {
        texteOUT[indexOUT++] = ConvertUtf8ToAscii(lettre);
        isUTF8 = false;
    }
    else if (lettre == UTF8prefix)
    {
        // c'est le premier octet d'un caractère accentué UTF-8
        isUTF8 = true;
    }
    else
    {
        // Ce n'est pas de l'UFT8: On convertit de l'Unicode en ASCII
        texteOUT[indexOUT++] = ConvertUnicodeToAscii(lettre);
        isUTF8 = false;
     }
  }
  // par sécurité, on force un Fin de Texte
  texteOUT[LINEMAX] = '\0';
  Serial.println();Serial.println(texteOUT); 
}
  

// ******************************************************************************
// Effacement du champ rectangulaire
// ******************************************************************************
void Display::clearField(int X, int Y, int W, int H)
{
  TFTscreen.stroke(BackgroundR, BackgroundG, BackgroundB);
  TFTscreen.fill  (BackgroundR, BackgroundG, BackgroundB);
  TFTscreen.rect(X,Y,W,H);
}


// ******************************************************************************
// Affiche tout les caractères de l'alphabet. Exemple:
//     060 <=>?@ABCDE FGHIJKLMNO
//     080 PQRSTUVWXY Z[\]^_`abc
//     100 defghijklm nopqrstuvw
// ******************************************************************************
void Display::printAllChars()
{
  char line[32];
  Serial.println("printAllChars");
  TFTscreen.setTextSize(1);              
  TFTscreen.stroke(DARK_R, DARK_G, DARK_B);          // set the font color
  for (byte y=1; y<13; y++)
  {
    line[0]= getHundrenChar(y*20);
    line[1]= getDozenChar(y*20);
    line[2]= getUnitChar(y*20);
    line[3]= ' ';
    for (byte x=0; x<10; x++)
    {
      line[x+4]= char(y*20+x);
    }
    line[14]= ' ';   // fin de ligne
    for (byte x=10; x<20; x++)
    {
      line[x+5]= char(y*20+x);
    }
    line[25]= '\0';   // fin de ligne
    TFTscreen.text(line, 4, y*10);
    Serial.println(line);
  }
}
