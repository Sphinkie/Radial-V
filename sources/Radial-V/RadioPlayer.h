/* ***********************************************************
 *  FM PLAYER
 *  
 *  Gestion de la carte Sparkfun FM player, en utilisant la 
 *  librairie "SparkFunSi4703" et le bus I2C
 *  
 * --------------------------------------------------------------------
 * Pins affectées au bus I2C
 * Arduino Uno:       A4 (SDA), A5 (SCL)
 * Arduino Mega2560:  20 (SDA), 21 (SCL)
 * --------------------------------------------------------------------
 * SI4703 = 0x10;         // I2C address of Si4703. Prédéfini dans la librarie <SparkFunSi4703>
 * PIN_SEN* = Choix du mode de fonctionnement: HIGH=2 fils (default, car pullup interne) | LOW=3 fils => Pas besoin de la cabler car on utilise la valeur par défaut.
************************************************************* */
#include "SparkFunSi4703.h"   // Library pour shield FM Si7403



#ifndef RADIOPLAYERCLASS_H_INCLUDED
#define RADIOPLAYERCLASS_H_INCLUDED

  #define  MIN_VOLUME 0
  #define  MAX_VOLUME 15
    
  class RadioPlayer : public Si4703_Breakout
  {
     public:
        RadioPlayer(int pinRESET, int pinSDIO, int pinSCLK, int pinSTC);
        void   initialize();
        void   displayInfos();
        void   manageRadio(char commande);
        void   listenRDSData();
        void   setChannel(int channel_nb);
                
     private:
        int channel;
        int volume;
        char rdsBuffer[10];
  };

#endif // RADIOPLAYERCLASS_H_INCLUDED
