/* ***********************************************************
 * Gestion de Bouton de type Capacimetre
 *  
 * Capacité à mesurer:
 *   La capacité à mesure est entre in_pin (Analog) et out_pin (Analog)
 * 
 * Capacité parasite (Stray):
 *   Capacitance between Pin_In and Ground.
 *   Stray capacitance is always present. 
 *   Extra capacitance can be added to allow higher capacitance to be measured.
 ************************************************************* */

#include "CapButton.h"

// **********************************************************
// Contructor
// **********************************************************
CapButton::CapButton(int in_pin, int out_pin)
{
 // On initialise les variables
  Pin_In        = in_pin;
  Pin_Out       = out_pin;
  PrevPrevValue = 0;
  LastValue     = 0;
  Value         = 0;
  Changed       = false;
  Stabilized    = true;

  // On initialise les outputs a leur état par defaut
  pinMode(out_pin, OUTPUT);
  digitalWrite(out_pin, LOW);
  pinMode(in_pin, OUTPUT);
  digitalWrite(in_pin, LOW);
}

// **********************************************************
// Initialisations
// **********************************************************
void CapButton::begin()
{
  this->dischargeCapacitor();
  // On dépoussière en lisant quelques premières valeurs
  this->captureMeanValue(4);

}

// **********************************************************
// On lit et renvoie la position de l'entrée digitale (valeur de 0 à 1023)
// Capacitor under test between Pin_out and Pin_In
// **********************************************************
int CapButton::readValue()
{
  // On met à jour l'historique
  PrevPrevValue=LastValue;
  LastValue=Value;

  // On mesure la valeur courante (moyenne de plusieurs captures)
  Value = this->captureMeanValue(7);

  // Au debut,on aligne les 3 valeurs de l'historique
  if (PrevPrevValue==0) PrevPrevValue=LastValue=Value;
  // Serial.print(F("  PrevPrevValue=")); Serial.print(PrevPrevValue); Serial.print(F(" LastValue=")); Serial.print(LastValue); Serial.print(F(" Value=")); Serial.println(Value);

  // Il y a Stabilisation si les trois valeurs de l'historique sont identiques (a l'imprécision près)
  if ( (abs(Value-LastValue)<IMPRECISION) and (abs(LastValue-PrevPrevValue)<IMPRECISION) ) Stabilized=true;
  //if (Stabilized) Serial.print("Stabilized ");
  // Il y a changement si la dernière valeur lue s'écarte de la précédente +/- IMPRECISION.
  if ( (abs(Value-LastValue)>IMPRECISION) and (abs(LastValue-PrevPrevValue)>IMPRECISION) ) {Changed=true;  Stabilized=false; }

/*
  Serial.print(F("Value = ")); Serial.print(Value);  
  Serial.print(" Delta= ");   Serial.print(abs(Value-LastValue));  
  Serial.print(" Changed=");  Serial.print(Changed);  
  Serial.print(" Stabilized=");  Serial.print(Stabilized);  
  Serial.println(F(". "));
*/
  return Value;
}

// **********************************************************
// On renvoie la position lue la plus récente (valeur de 0 à 1023)
// **********************************************************
int CapButton::getValue()
{
//  Changed = false;
  return Value;
}

// **********************************************************
// On renvoie la position lue précédente (valeur de 0 à 1023)
// **********************************************************
int CapButton::getLastValue()
{
    return LastValue;
}

// **********************************************************
// Indique si le bouton a changé de position depuis le dernier appel à la fonction
// et s'est stabilisé.
// **********************************************************
bool CapButton::hasChanged()
{
  bool ChangedAndStabilized = (Changed and Stabilized);
  if (ChangedAndStabilized) Changed = false;
  return ChangedAndStabilized;
}
        
// **********************************************************
// Effectue plusieurs mesures pour obtenir une moyenne
// Les valeurs mesurées vont de 340 à 120 (cad une amplitude de 220 env).
// On les étale entre 0 et 1023.
// **********************************************************
int CapButton::captureMeanValue(int samples)
{
  float somme   = 0;
  float moyenne = 0;
  double value  = 0;
  #define MINLIM 80               // la valeur la plus petite, jamais mesurée est de 90
  
  for (int i=0; i<samples; i++)
  {
    int measure = this->chargeAndMesure();
    delay(1);
    somme +=measure;
  }
  
  moyenne = somme/samples;         // moyenne varie entre 125 et 330 
//  Serial.print(F("  moyenne= "));  Serial.print(moyenne);  
  value = log10(moyenne-MINLIM);   // value varie entre 1.2 et 2.3
  value = (value-1)*755;           // on étale entre 0 et 1023
  value = max(0,value);            // on sature aux bornes 
  value = min(value,1023);
//  Serial.print(F("  valeur lue calibree= "));  Serial.println(int(value));
  return (int(value));
}
        
// **********************************************************
// Effectue une lecture de la valeur.
// On envoie une impulsion sur Pin_Out
// et 0.1ms plus tard, on lit la valeur de Pin_In
// **********************************************************
int CapButton::chargeAndMesure()
{
  int measure;
   // On génère un Front Montant (charge) sur Pin_Out
   pinMode(Pin_In, INPUT);
   digitalWrite(Pin_Out, HIGH);
   // On lit la valeur sur Pin_In (pendant la décharge)
  measure = analogRead(Pin_In);

  // On redescend le niveau sur Pin_Out (le creneau a duré 0.1 ms)
  digitalWrite(Pin_Out, LOW);
  pinMode(Pin_In, OUTPUT);

  // on calcule la valeur en pF
  // float capacitance = (float)measure * IN_CAP_TO_GND / (float)(MAX_ADC_VALUE - measure);
  // on trace les valeurs lue et calculée
  // Serial.print(F("   measure = "));  Serial.println(measure);  
  // Serial.print(F("Capacitance Value = "));  Serial.print(capacitance, 3);  Serial.print(F(" pF "));

 return (measure);
}


// **********************************************************
// Décharge la Capa en mettant la masse sur les deux pins
// **********************************************************
void CapButton::dischargeCapacitor()
{
  pinMode(Pin_Out, OUTPUT);
  pinMode(Pin_In,  OUTPUT);
  digitalWrite(Pin_In,  LOW);
  digitalWrite(Pin_Out, LOW);
  delay (200);
}
