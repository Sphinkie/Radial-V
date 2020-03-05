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
// Constructor
// **********************************************************
CapButton::CapButton(int in_pin, int out_pin)
{
 // On initialise les variables
  Pin_In        = in_pin;   // Discharge pin.
  Pin_Out       = out_pin;  // Charge pin.  Créneaux de 5v.
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
// On lit et renvoie la position de l'entrée analogique
// **********************************************************
int CapButton::readValue(bool debug = false)
{
  // On met à jour l'historique
  PrevPrevValue=LastValue;
  LastValue=Value;

  // On mesure la valeur courante (moyenne de plusieurs captures)
  Value = this->captureMeanValue(4);

  // Au debut,on aligne les 3 valeurs de l'historique
  if (PrevPrevValue==0) PrevPrevValue=LastValue=Value;
  // Serial.print(F("  PrevPrevValue=")); Serial.print(PrevPrevValue); Serial.print(F(" LastValue=")); Serial.print(LastValue); Serial.print(F(" Value=")); Serial.println(Value);

  // Il y a Stabilisation si les trois valeurs de l'historique sont identiques (a l'imprécision près)
  if ( (abs(Value-LastValue)<IMPRECISION) and (abs(LastValue-PrevPrevValue)<IMPRECISION) ) Stabilized=true;
  //if (Stabilized) Serial.print("Stabilized ");
  // Il y a changement si la dernière valeur lue s'écarte de la précédente +/- IMPRECISION.
  if ( (abs(Value-LastValue)>IMPRECISION) and (abs(LastValue-PrevPrevValue)>IMPRECISION) ) {Changed=true;  Stabilized=false; }

  if (debug)
  {
     Serial.print(F(" Value="  ));    Serial.print(Value);  
     Serial.print(F(" Delta="  ));    Serial.print(abs(Value-LastValue));  
     Serial.print(F(" Changed="));    Serial.print(Changed);  
     Serial.print(F(" Stabilized=")); Serial.print(Stabilized);  
     Serial.println(".");
  }
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
// Effectue plusieurs mesures pour obtenir une moyenne.
//   samples = nombre de mesures
//   ecart   = ecart entre chaque mesure (en ms)
// On les étale entre 0 et 1023.
// **********************************************************
int CapButton::captureMeanValue(int samples, int ecart=5)
{
  float somme   = 0;
  float moyenne = 0;
  int   value  = 0;
  
  for (int i=0; i<samples; i++)
  {
     int measure = this->chargeAndMesure();
     delay(ecart);
     somme +=measure;
  }
  
  moyenne = somme/samples;
  Serial.print(F("  moyenne= "));  Serial.print(moyenne);
  value=this->normalizeValue(moyenne);
  Serial.print(F("  valeur lue calibree= "));  Serial.println(int(value));
  return (value);
}
        
// **********************************************************
// Effectue une lecture de Pin_In (mesure théoriquement entre 0 et 1023).
// On envoie une impulsion sur Pin_Out et 0.1ms plus tard, on lit la valeur de Pin_In
// **********************************************************
int CapButton::chargeAndMesure()
{
   int measure;
   // On génère un Front Montant (charge) sur Pin_Out
   pinMode(Pin_In, INPUT);
   digitalWrite(Pin_Out, HIGH);   // Durée avant exécution = environ 2ms
   // On lit la valeur sur Pin_In (pendant la charge)
   measure = analogRead(Pin_In);  // Durée environ 0.1ms
   // On redescend le niveau sur Pin_Out (le creneau a duré 0.1 ms)
   digitalWrite(Pin_Out, LOW);
   pinMode(Pin_In, OUTPUT);

 return (measure);
}


// **********************************************************
// Décharge la Capa en mettant les deux pins à LOW (=GND)
// **********************************************************
void CapButton::dischargeCapacitor()
{
   pinMode(Pin_Out, OUTPUT);
   pinMode(Pin_In,  OUTPUT);
   digitalWrite(Pin_In,  LOW);
   digitalWrite(Pin_Out, LOW);
   delay (200);
}


// **********************************************************
// Normalise la valeur
// **********************************************************
int CapButton::normalizeValue(float value)
{
  // Normalisation linéaire inversée:
  value = MAX_VALUE - value;
  value = value * FACTOR;
  // Normalisation logarithmique:
  // value = log10(value-MIN_VALUE);  // value varie entre 1.2 et 2.3
  // value = (value-1)*755;           // on étale entre 0 et 1023
  // Gestion des limites:
  value = max(0,value);
  value = min(value,1023);

 return (int(value));
}
