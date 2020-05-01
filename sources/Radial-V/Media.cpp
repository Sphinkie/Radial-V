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
}

// *******************************************************************************
// Autres fonctions: Setters et Getters
// *******************************************************************************
int    Media::getYear()      {return Field1.toInt();}
String Media::getID()        {return Field2;}
String Media::getGenre()     {return Field3;}
int    Media::getRating()    {return Field4.toInt();}
bool   Media::isSelected()   {return Selected;}
long   Media::getNextMediaPosition()   {return NextMediaPosition;}
long   Media::getRatingPosition()      {return NextMediaPosition-4;}
void   Media::setSelected(bool select) {Selected=select;}
void   Media::setRating(int rating)    {Field4=String(rating);}
void   Media::setNextMediaPosition(long pos)    {NextMediaPosition=pos;}

// *******************************************************************************
// *******************************************************************************
bool Media::hasYearBetween(int YearStart, int YearEnd)
{
  int year = Field1.toInt();
  return ((year>=YearStart) && (year<YearEnd));
}


// *******************************************************************************
// Renvoie TRUE si le genre du média est egal au Genre demandé.
// Renvoie TRUE si le genre du média est "hors-WhiteList" et le genre demandé est "*"
// *******************************************************************************
bool Media::hasGenre(String genre)
{
  //  Serial.println ("hasGenre "+genre);
  if (genre=="*") 
    // si le genre attendu est Others, alors on regarde si le genre lu est dans la Whitelist
    // Si il est dedans : on renvoie FALSE.
    {
      Serial.print (" others:"+Field3+":"); Serial.println (GenreWhiteList.indexOf(Field3));
      return (GenreWhiteList.indexOf(Field3)==-1); // -1=>on n'a pas trouvé=> on renvoie VRAI
    }
  else 
    // si le genre attendu est defini, on le compare au genre lu
    return (Field3.equalsIgnoreCase(genre));
}
