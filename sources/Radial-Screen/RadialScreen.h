
    // ------------------------------------
    // Les interlocuteurs du bus I2C
    // ------------------------------------
    #define TFT_SLAVE 0x2   // Arduino avec écran TFT
    
    
    // ------------------------------------
    // Les commandes I2C
    // ------------------------------------
    #define C_TITLE1          1   // + texte
    #define C_TITLE2          2   // + texte
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
    #define C_ICON1           16   // audio icon
    #define C_ICON2           17   // dance icon
    #define C_ASCII           18   // Affiche toute la table ASCII de l'afficheur TFT

    
