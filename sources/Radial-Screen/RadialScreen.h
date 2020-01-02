/* ************************************************************************************************
 *    RADIAL-SCREEN
 *
 *  Software pour la radio Radial-V.
 *  Ce composant (SLAVE) est piloté par le Arduino MASTER.
 *  
 *  Ci-dessous, on configure la liste des commandes gérées par le SLAVE
 ************************************************************************************************* */

// *******************************************************************************
// Cablage
// *******************************************************************************
#define BACKLIGHT 45  // PWM                              (TFT pin 2)
#define RESET_LD  43  // Reset du TFT                     (TFT pin 3)
#define DC_LD     41  // Data/Command du TFT              (TFT pin 4)
#define CS_SD     39  // SPI Slave Select pour carte SD   (TFT pin 5)
#define CS_LD     37  // SPI Slave Select pour ecran TFT  (TFT pin 6)

// Sur le connecteur ICSP:
#define MOSI      51  // SPI MOSI pour UNO or ICSP-4 (51 sur MEGA) (11 sur UNO)
#define MISO      50  // SPI MISO pour UNO or ICSP-1 (50 sur MEGA) (12 sur UNO)
#define SCK       52  // SPI SCK  pour UNO or ICSP-3 (52 sur MEGA) (13 sur UNO)
#define SS_SLAVE  53  // SPI Slave Select pour UNO   (53 sur MEGA) (10 sur UNO) Non utilisé ici car Arduino est MASTER


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

    
