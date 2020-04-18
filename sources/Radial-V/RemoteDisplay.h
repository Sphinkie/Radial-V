// *******************************************************************************
// REMOTE DISPLAY
//
// Cet objet envoie des commandes à un écran TFT via un bus I2C.
// Il y a un autre Arduino (slave) sur le bus I2C pour recevoir ces commandes
// *******************************************************************************

#ifndef REMOTEDISPLAYCLASS_H_INCLUDED
#define REMOTEDISPLAYCLASS_H_INCLUDED

class RemoteDisplay
{

  public:
    RemoteDisplay();
    void initI2C();
    bool isSlavePresent();
    void setSlavePresent(bool present);
    void clearBackground();
    void setBackgroundImage();
    void printTitle(String texte);
    void printSplitedTitle(String texte);
    void printArtist(String texte);
    void printAlbum(String texte);
    void printYear(String texte);
    void printGenre(String texte);
    void printLog(String texte);
    void printStars(String texte);
    void clearAllText();
    void setBacklight(bool on);
    void printPictoMute();
    void printPictoFM();
    void clearPicto();
    char requestStatus();
    
  private:

    bool I2Cconnected;
    
    // ------------------------------------
    // Les interlocuteurs du bus I2C
    // ------------------------------------
    #define TFT_SLAVE 0x02   // Arduino avec écran TFT
    
    
    // ------------------------------------
    // Les commandes I2C
    // ------------------------------------
    #define C_TITLE1          1   // + texte (ligne 1)
    #define C_TITLE2          2   // + texte (ligne 2)
    #define C_ARTIST          3   // + texte
    #define C_ALBUM           4   // + texte
    #define C_YEAR            5   // + texte
    #define C_GENRE           6   // + texte
    #define C_LOG             7   // + texte
    #define C_STARS           8   // + nombre (en ASCII)
    #define C_CLEARTEXT       9    // efface toute la zone texte 
    #define C_BACKGROUNDIMAGE 10   // affiche l'image de fond
    #define C_CLEAR           11   // clear background
    #define C_BLON            12   // TFT Backlight ON
    #define C_BLOFF           13   // TFT Backlight OFF
    #define C_ICON0           15   // clear last icon
    #define C_ICON1           16   // medium icon
    #define C_ICON2           17   // large icon
    #define C_ASCII           18   // Affiche toute la table ASCII de l'afficheur TFT
    #define C_TITLE           19  // + texte (deroulant)

};


#endif // REMOTEDISPLAYCLASS_H_INCLUDED
