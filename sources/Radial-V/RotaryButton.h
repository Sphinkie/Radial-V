/* ***********************************************************
 *  Gestion de Bouton de type Commutateur Rotatif
 *  
 *  On considère en dur qu'il y a 4 positions.
 *  Donc, on réserve 4 entrées Digitales pour ce bouton.
 *  
 * mode INPUT:
 *   Pushbutton attached to pin N from +5V
 *   10K resistor attached to pin N from Ground. 
 *   Cela permet que les entrée au repos (normaly open) soient à la masse.
 ************************************************************* */


#ifndef ROTARYCLASS_H_INCLUDED
#define ROTARYCLASS_H_INCLUDED


class Rotary
{
    public:
      Rotary(int pin1, int pin2, int pin3, int pin4);
      Rotary(int pin1, int pin2);
      int    readPosition();
      int    getValue();
      int    getLastValue();
      bool   hasChanged();
        
    private:

    //variables:
      int   Value;
      int   LastValue;
      bool  Changed;
      int   Pin1,Pin2,Pin3,Pin4;
 
};

#endif // ROTARYCLASS_H_INCLUDED
 
 
 
