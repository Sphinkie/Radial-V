/* ***********************************************************
 *  FM PLAYER
 *  
 *  Gestion de la carte Sparkfun FM player, en utilisant la 
 *  librairie "SparkFunSi4703" et le bus I2C
 *  
 ************************************************************* */
#ifndef FMPLAYERCLASS_H_INCLUDED
#define FMPLAYERCLASS_H_INCLUDED

class FMplayer
{
    public:
        FMplayer();
        void   initialize();
        void   displayInfo();
        void   manage(char commande);

    private:
      int channel;
      int volume;
      char rdsBuffer[10];
};

    // --------------------------------------------------------------------
    // Pins affectées au bus I2C
    // Arduino Uno:       A4 (SDA), A5 (SCL)
    // Arduino Mega2560:  20 (SDA), 21 (SCL)
    // --------------------------------------------------------------------
    #define SDIO       20     // I2C communication
    #define SCLK       21     // I2C communication
    #define FM_RESET   17     // D17 output : FM shield RST* command (active LOW)
    #define FM_STC     23     // D23 input  : FM shield pulse received then Seek/Tune completed. (pin GPI02 du shield FM Si7403)  

    // SI4703 = 0x10;         // I2C address of Si4703. Prédéfini dans la librarie <SparkFunSi4703>
    // PIN_SEN* = Choix du mode de fonctionnement: HIGH=2 fils (default, car pullup interne) | LOW=3 fils => Pas besoin de la cabler car on utilise la valeur par défaut.
    
    #define  MIN_VOLUME 0
    #define  MAX_VOLUME 15


#endif // FMPLAYERCLASS_H_INCLUDED
