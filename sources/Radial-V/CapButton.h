/* ***********************************************************
 *  Gestion de Bouton de type Capacimètre
 *  
  ************************************************************* */


#ifndef CAPACIMETRECLASS_H_INCLUDED
#define CAPACIMETRECLASS_H_INCLUDED


class CapButton
{
    public:
        CapButton(int in_pin,int out_pin);
        void   begin();
        int    readValue(bool debug = false);
        int    getValue();
        int    getLastValue();
        bool   hasChanged();
        void   dischargeCapacitor();
        
    private:
        int    captureMeanValue(int samples, int ecart=5);
        int    chargeAndMesure();
        int    normalizeValue(float value);
        
    //variables:
        int   Value;
        int   LastValue;
        int   PrevPrevValue;
        bool  Changed;
        bool  Stabilized;
        int   Pin_In,Pin_Out;

        const float MIN_VALUE = 30.0;   // la valeur la plus petite, jamais mesurée.
        const float MAX_VALUE = 400.0;  // la valeur la plus grande, jamais mesurée.
        const float FACTOR = 1023.0/(MAX_VALUE-MIN_VALUE);
        // Le status hasChanged est positionné si la variation est supérieure à l'imprecision
        // (en effet la valeur lue oscille légèrement)
        const int  IMPRECISION = 2*FACTOR;

        const float IN_STRAY_CAP_TO_GND = 26.32; //initially this was 30.00
        const float IN_EXTRA_CAP_TO_GND = 0.0;
        const float IN_CAP_TO_GND       = IN_STRAY_CAP_TO_GND + IN_EXTRA_CAP_TO_GND;
        const int   MAX_ADC_VALUE       = 1023;

/*
 * Etalonnage: 
 *  Pour avoir une meilleure précison, il faut connaitre la valeur de la capacité parasite C1.
 *  Elle est d'environ 30pF, mais il faut être plus précis, et faire un calibrage.
 *  
 *  Pout cela, j'utilise une capa CT de 100pF (valeur exacte au multimètre= 102pF, par exemple). 
 *  L'Arduino renvoie 125pF (ADC value 825). 
 *  On positionne alors les values suivantes dans l'équation C1 = CT x (V2-V1) / V1
 *     V1 = 825
 *     V2 = 1023 
 *     CT = 102 
 *  et on obtient C1 =24.48pF
 *  On configure alors: 
 *     IN_STRAY_CAP_TO_GND = 24.48 
*/
      
};

#endif // CAPACIMETRECLASS_H_INCLUDED
 
