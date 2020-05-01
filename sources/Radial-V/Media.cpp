/* *******************************************************************************
 *  Gestion d'un MEDIA du catalogue
 ********************************************************************************/
#include "Arduino.h"
#include "Media.h"


// *******************************************************************************
// Constructeur
// *******************************************************************************
Media::Media()
{
    Field1 = "0000";
    Field2 = "NOISE";
    Field3 = "-";
    Field4 = "-";
}

 
// *******************************************************************************
// Parsing des 4 champs d'une ligne de catalogue  (ex: 1956;E76E79B1;Calipso;0; )
// *******************************************************************************
void Media::fillWith(String medialine)
{
  // Serial.print("  parsing: "); Serial.println (medialine);
  if (medialine.length()<18) 
  {
    // Si la ligne est trop courte pour être exploitable, on met les valeurs par défaut
    Field1 = "0000";
    Field2 = "NOISE";
    Field3 = "-";
    Field4 = "-";
  }
  else
  {
    // Si la ligne a une longueur correcte, on fait le parsing
    int    Separ1   = medialine.indexOf(';');              // pointeur sur le premier séparateur
    int    Separ2   = medialine.indexOf(';',Separ1+1);     // pointeur sur le second séparateur
    int    Separ3   = medialine.indexOf(';',Separ2+1);     // pointeur sur le troisième séparateur
    int    Separ4   = medialine.indexOf(';',Separ3+1);     // pointeur sur le quatrième séparateur
    Field1 = medialine.substring(0       ,Separ1);
    Field2 = medialine.substring(Separ1+1,Separ2);
    Field3 = medialine.substring(Separ2+1,Separ3);          
    Field4 = medialine.substring(Separ3+1,Separ4);
  }

  // Si après le parsing, un des champs est vide, on met la valeur par défaut
  if (Field1.length()==0) Field1="0000";
  if (Field2.length()==0) Field2="NOISE";
  if (Field3.length()==0) Field3="-";
  if (Field4.length()==0) Field4="-";

  // On mémorise la position du field Rating
  // RatingPosition = getCurrentPosition()-4;
}

String Media::getYear()   {return Field1;}
String Media::getID()     {return Field2;}
String Media::getGenre()  {return Field3;}
String Media::getRating() {return Field4;}
bool   Media::isSelected(){return Selected;}
void   Media::setSelected(bool select) {Selected=select;}

bool Media::isGenre(String genre)
{
  return (genre==Field3);
}

bool Media::hasYearBetween(int YearStart, int YearEnd)
{
  int year = Field1.toInt();
  return ((year>=YearStart) && (year<YearEnd));
}
