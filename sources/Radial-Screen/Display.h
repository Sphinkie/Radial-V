#ifndef DISPLAYCLASS_H_INCLUDED
#define DISPLAYCLASS_H_INCLUDED

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

#include <SD.h>       // pour le type File
#include <TFT.h>      // opur le type PImage


#define LINEMAX     32              // Taille maximum des textes. Au dela: on tronque.

// Position (verticale) des textes
#define Y_TOPMARGIN 5
#define Y_YEAR      Y_TOPMARGIN+10
#define Y_GENRE     Y_TOPMARGIN+10
#define Y_TITLE     Y_TOPMARGIN+30
#define Y_ARTIST    Y_TOPMARGIN+57
#define Y_ALBUM     Y_TOPMARGIN+72
#define Y_STARS     Y_TOPMARGIN+82
#define Y_TRACE     Y_TOPMARGIN+110

// Position (horizontale) des textes
#define X_MARGIN    13
#define X_STARS     13
#define X_YEAR      X_MARGIN+14
#define X_GENRE     X_YEAR+30

// Couleur des textes (hors log, qui est rouge)
#define DARK_R 75
#define DARK_G 58
#define DARK_B 22
// Couleur des textes grisés
#define GREYED_R 115
#define GREYED_G 115
#define GREYED_B 60

// Couleur du fond (jaune comme le boitier)
#define BG_R           210
#define BG_G           210
#define BG_B           0

// **********************************************************************
// **********************************************************************
class Display
{

  public:
    Display();
    void initDisplay();
    void setBackground(int R, int G, int B);
    void setBackgroundImage(char* filename);
    void printText(char* texte);
    void printTitle(String texte);
    void printArtist(String texte);
    void printAlbum(String texte);
    void printYear(String texte);
    void printGenre(String texte);
    void printLog(String texte);
    void printStars(int number);
    void eraseText(char* texte, int X, int Y);
    void ls();
    void clearStars();
    void clearAllTexts();
    void setBacklight(int value);
    void showPicto(String filename, int x, int y);
    void clearPicto();
    
  private:
    void cleanString(String texteIN,char* texteOUT);
    void printDirectory(File dir, int numTabs);
    void clearField(int X, int Y, int W, int H);
    void printAllChars();

    PImage  StarOn;
    PImage  StarOff;
    PImage  BackgroundImage;
    PImage  Picto;

    // couleur de fond
    int      BackgroundR = 0;
    int      BackgroundG = 0;
    int      BackgroundB = 0;
    // mémorisation des textes affichés (pour pouvoir les effacer).
    char     CurrentText[LINEMAX];
    char     CurrentTitle1[LINEMAX];
    char     CurrentTitle2[LINEMAX];
    char     CurrentArtist[LINEMAX];
    char     CurrentAlbum[LINEMAX];
    char     CurrentYear[5];
    char     CurrentGenre[LINEMAX];
    char     CurrentLog[LINEMAX];
    // coordonnées du dernier picto affiché
    byte     PictoX = 30;
    byte     PictoY = 21;
    byte     PictoW = 0;
    byte     PictoH = 0;

};


#endif // DISPLAYCLASS_H_INCLUDED
