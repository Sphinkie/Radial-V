/* *******************************************************************************
 *  Gestion du catalogue des MP3
 ********************************************************************************/
#include "Arduino.h"
#include "Catalog.h"
#include "Media.h"


// *******************************************************************************
// Constructor (avec Classe de base = CatalogFile)
// *******************************************************************************
Catalog::Catalog() : CatalogFile()
{
}

// *******************************************************************************
// N'a besoin d'être fait qu'une fois, mais pas immédiatement car la carte SD doit être prête.
// *******************************************************************************
void Catalog::initialize()
{
  CatalogFile::begin();
}

// *******************************************************************************
// Il faut appeler cette méthode lorsque le tuning a changé.
// On récupère les valeurs texuelles du Genre/Year/Rating demandé par le bouton Tuning
// *******************************************************************************
void Catalog::setNewRequestedValues(int tuning)
{
  Serial.println(" setNewRequestedValues for tuning "+String(tuning));
  RequestedGenre = this->getGenreLabel(tuning); // La valeur textuelle du genre demandé
  RequestedYear  = this->getYearValue(tuning);  // La valeur textuelle de l'année demandée
  RequestedRating= this->getStarsValue(tuning); // La valeur textuelle du rating demandé
}

// *******************************************************************************
// Renvoie l'ID qui a été trouvé lors du GetNextClip
// *******************************************************************************
String Catalog::getSelectedClipID()
{
  return NextMediaToPlay.getID();
}

// *******************************************************************************
// Renvoie le genre qui a été trouvé lors du GetNextClip
// *******************************************************************************
String Catalog::getSelectedClipGenre()
{
  return NextMediaToPlay.getGenre();
}

// *******************************************************************************
// Renvoie l'Année qui a été trouvé lors du GetNextClip
// *******************************************************************************
String Catalog::getSelectedClipYear()
{
  return NextMediaToPlay.getYear();
}

// *******************************************************************************
// Renvoie l'ID qui a été trouvé lors du GetNextClip
// *******************************************************************************
String Catalog::getSelectedClipRating()
{
  return NextMediaToPlay.getRating();
}

// *******************************************************************************
// Renvoie la position du curseur pour le Rating
// *******************************************************************************
long Catalog::getRatingPosition()
{
  return RatingPosition;
}

// *********************************************************************
// Renvoie le GENRE correspondant à la position du bouton TUNE
//   "Classique;Blues;Jazz;Folk;Rock n'Roll;Rock;Chanson;Musiques du monde;"
// On positionne aussi GenreLength qui correspond à la 'largeur' de ce genre
// *********************************************************************
String Catalog::getGenreLabel(int tuning)
{
  if (tuning < 360)  {GenreLength=360; return "Classique"; }
  if (tuning < 450)  {GenreLength=90;  return "Blues"; }
  if (tuning < 530)  {GenreLength=80;  return "Jazz"; }
  if (tuning < 630)  {GenreLength=100; return "Folk"; }
  if (tuning < 700)  {GenreLength=70;  return "Rock n'Roll"; }
  if (tuning < 750)  {GenreLength=50;  return "Rock"; }
  if (tuning < 840)  {GenreLength=90;  return "Chanson"; }
  if (tuning < 890)  {GenreLength=50;  return "Musiques du monde"; }
  return "*";    // Genre "Autres"
}


// *********************************************************************
// Renvoie le RATING correspondant à la position du bouton TUNE
// *********************************************************************
int Catalog::getStarsValue(int value)
{
  if (value < 300)  {return 0; }   /* 000..300  : 0 étoile  */
  if (value < 450)  {return 1; }   /* 300..450  : 1 étoile  */  
  if (value < 580)  {return 2; }   /* 450..580  : 2 étoiles */
  if (value < 680)  {return 3; }   /* 580..680  : 3 étoiles */
  if (value < 780)  {return 4; }   /* 680..780  : 4 étoiles */
  else  {return 5; }               /* 780..1023 : 5 étoiles */
}

// *********************************************************************
// Renvoie l'ANNEE correspondant à la position du bouton TUNE
// *********************************************************************
int Catalog::getYearValue(int tuning)
{
  /*
   map(value, fromLow, fromHigh, toLow, toHigh)
   Parameters
     value: the number to map.
     fromLow:  the lower bound of the value’s current range.
     fromHigh: the upper bound of the value’s current range.
     toLow:  the lower bound of the value’s target range.
     toHigh: the upper bound of the value’s target range.
  */
  if (tuning < 270)       {RangeStart=0;    RangeEnd=1700; return map(tuning,   0, 270,RangeStart,RangeEnd);    } // 0000...1700
  if (tuning < 360)       {RangeStart=1700; RangeEnd=1800; return map(tuning, 270, 360,RangeStart,RangeEnd);    } // 1700...1800
  if (tuning < 410)       {RangeStart=1800; RangeEnd=1900; return map(tuning, 360, 410,RangeStart,RangeEnd);    } // 1800...1900
  if (tuning < 460)       {RangeStart=1900; RangeEnd=1940; return map(tuning, 410, 460,RangeStart,RangeEnd);    } // 1900...1940
  if (tuning < 540)       {RangeStart=1940; RangeEnd=1950; return map(tuning, 460, 530,RangeStart,RangeEnd);    } // 40's
  if (tuning < 600)       {RangeStart=1950; RangeEnd=1960; return map(tuning, 530, 600,RangeStart,RangeEnd);    } // 50's
  if (tuning < 700)       {RangeStart=1960; RangeEnd=1970; return map(tuning, 600, 700,RangeStart,RangeEnd);    } // 60's
  if (tuning < 790)       {RangeStart=1970; RangeEnd=1980; return map(tuning, 700, 790,RangeStart,RangeEnd);    } // 70's
  if (tuning < 840)       {RangeStart=1980; RangeEnd=1990; return map(tuning, 790, 840,RangeStart,RangeEnd);    } // 80's
  if (tuning < 860)       {RangeStart=1990; RangeEnd=2000; return map(tuning, 840, 860,RangeStart,RangeEnd);    } // 1990...2000
  if (tuning < 1023)      {RangeStart=2000; RangeEnd=2050; return map(tuning, 860,1023,RangeStart,RangeEnd);    } // 2000...2050
}


// *******************************************************************************
// Debug: Affiche tous les genres en fonction de la valeur du "tuning"
// *******************************************************************************
void Catalog::debugGenre()
{
  for (int i=0; i<MAX_TUNING; i++)
  {
    Serial.print(i);Serial.print("=>");Serial.println(this->getGenreLabel(i));
  }
}

// *******************************************************************************
// Debug: Affiche toutes les années en fonction de la valeur du "tuning"
// *******************************************************************************
void Catalog::debugYear()
{
  for (int i=0; i<MAX_TUNING; i++)
  {
    Serial.print(i);Serial.print("=>");Serial.println(this->getYearValue(i));
  }
}

// *******************************************************************************
// Renvoie un ID de clip au hasard, tiré dans le catalogue.
// *******************************************************************************
String Catalog::selectRandomClip()
{
  String  medialine;
  bool    FileAccessOK;
  String  LastMedia_ID;
  String  NextMedia_ID;

  // On ouvre le fichier
  FileAccessOK = this->openCatalogAtPosition();
  // En cas d'erreur d'ouverture du fichier, on renvoie "NOISE.MP3"
  if (!FileAccessOK) return ("NOISE");
  
  // On lit une ligne au hasard dans le fichier
  medialine = this->readRandomLine();
  this->closeCatalog(); 
  if (medialine=="ERROR") {return "NOISE";}    
  if (medialine=="EOF")   {return "NOISE";}
  
  // Serial.print(F("  line read: ")); Serial.println (LineRead);
  
  // on parse la ligne du media trouvé pour extraire l'ID
  LastMedia_ID = NextMediaToPlay.getID();
  NextMediaToPlay.fillWith(medialine);
  NextMedia_ID = NextMediaToPlay.getID();

  // Si on est tombé 2 fois sur le même ID, on met du Noise
  if (LastMedia_ID==NextMedia_ID) return "NOISE";

  // On retourne l'ID du media trouvé
  return NextMedia_ID;
}


// *******************************************************************************
// Renvoie l'ID du Clip suivant dans l'index, correspondant au genre demandé.
// On commence la recherche à partir de CurrentPosition (qui est l'emplacement du dernier clip joué),
// ou du début, si on a fait un initSearch.

// A OPTIMISER

// *******************************************************************************
String Catalog::selectClipForRequestedGenre(int tuning)
{
  bool   FileAccessOK;
  String medialine;
  bool   found = false;
  
  RequestedGenre = this->getGenreLabel(tuning); // La valeur textuelle du genre demandé
  Serial.println ("  selectClipForRequestedGenre: "+RequestedGenre);
    
  // On se positionne a la dernière position utilisée pour Genre.
  FileAccessOK = this->openCatalogAtPosition(CurrentPositionG);
  // En cas d'erreur d'ouverture du fichier, on renvoie "NOISE.MP3"
  if (!FileAccessOK) return ("NOISE");

  // On lit des lignes jusqu'à ce qu'on trouve une ligne du genre demandé (ou pas)
  for (int i=0; i<100; i++)
  {
     // On lit une ligne
     medialine = this->readNextLine();
     if (medialine=="ERROR") {this->closeCatalog(); return "NOISE";}    
     if (medialine=="EOF")   {this->closeCatalog(); this->findFirstClipForRequestedGenre(1); return "NOISE";}
     // Serial.print (F("  line read in Catalog.ndx: ")); Serial.println (medialine);
     CurrentPositionG = getCurrentPosition();  // On mémorise la position courante
     // on parse la ligne pour connaitre le genre que l'on compare au genre attendu
     CursorMedia.fillWith(medialine);
     if (CursorMedia.isGenre(RequestedGenre))
     {
        found = true;
        NextMediaToPlay=CursorMedia;
        break;
     }
  } 
  
  this->closeCatalog(); 
  return found;
}

// *******************************************************************************
// Renvoie le clip suivant dans l'index, correspondant à une periode allant 
// de l'année sélectionnée à la fin de la période.
// La fin de la période est définie dans getYearValue().
// L'index (ordonné) Catalog.ndx permet d'avancer d'année en année.
// *******************************************************************************
String Catalog::selectClipForRequestedYear()
{
  bool   FileAccessOK;
  String medialine;
 
  Serial.print(F("  selectClipForRequestedYear: ")); Serial.println(RequestedYear);

  FileAccessOK = this->openCatalogAtPosition(CurrentPositionY);
  // En cas d'erreur d'ouverture du fichier, on renvoie "NOISE.MP3"
  if (!FileAccessOK) return ("NOISE");

  // On lit la ligne suivante
  medialine = readNextLine();
  if (medialine=="ERROR") {closeCatalog(); return "NOISE";}    
  if (medialine=="EOF")   {closeCatalog(); return "NOISE";}

  Serial.print (F("  line read: ")); Serial.print (medialine);
  CurrentPositionY = getCurrentPosition();  // On mémorise la position courante
  closeCatalog();

  this->parseFields(medialine);
  // On verifie si le YEAR lu est toujours bien dans la période musicale demandée
  if (Field3.toInt()>RangeEnd)
  {
    // Si on déborde, alors on rewinde.
    CurrentPositionY=FirstcurrentPositionY;
    /*
    Media_Year  = FirstMediaYear;
    Media_ID    = FirstMediaID;
    Media_Genre = FirstMediaGenre;
    Media_Rating= FirstMediaRating;
    */
  }
  else
  {
    // On memorise l'ID Media trouvé
    /*
    Media_Year  = Field1;
    Media_ID    = Field2;
    Media_Genre = Field3;
    Media_Rating= Field4;
    */
  }
  // Retourne l'ID du media à jouer
  return Media_ID;
}


// *******************************************************************************
// On renvoie un clip au hasard, mais ayant le nombre d'étoiles demandé.
// *******************************************************************************
String Catalog::selectClipForRequestedRating()
{
  String medialine;
  bool   FileAccessOK;

  Serial.print(F("  selectClipForRequestedRating ")); Serial.println(RequestedRating);

  FileAccessOK = this->openCatalogAtPosition();
  // En cas d'erreur d'ouverture du fichier, on renvoie "NOISE.MP3"
  if (!FileAccessOK) return ("NOISE");
  
  // On lit une ligne au hasard dans le fichier
  medialine = this->readRandomLine();
  if (medialine=="ERROR")  {closeCatalog(); return "NOISE";}  
  if (medialine=="EOF")    {closeCatalog(); return "NOISE";}
  Serial.print (F(" line read: ")); Serial.print (medialine);
  this->parseFields(medialine);

  // Si ce clip n'a pas assez d'étoiles, alors on on lit la ligne suivante
  while (!this->isAsExpectedRating(Field4))
  {
        medialine=this->readNextLine();
        if (medialine=="ERROR")  {closeCatalog(); return "NOISE";}  
        if (medialine=="EOF")    {closeCatalog(); return "NOISE";}  
        this->parseFields(medialine);
  } 
  closeCatalog();

  // on envoie l'ID du media trouvé
  return (Media_ID);
}




// *******************************************************************************
// Initialisation des recherches de clip pour une année donnée.
// Il faut appeler cette méthode lorsque l'année demandée change, ou que l'on vient de basculer sur le mode "YEAR".
// Cette fonction parcourt le Catalogue depuis le début jusqu'à trouver une année qui correspond à l'année demandée.
// Cette fonction initialise FirstcurrentPositionY et CurrentPositionY.

// A OPTIMISER

// *******************************************************************************
void Catalog::findFirstClipForRequestedYear()
{
  String medialine;

  Serial.print(F(" findFirstClipForRequestedYear ")); Serial.println(RequestedYear);
  // on se positionne au debut du Catalogue
  openCatalogAtPosition();

  // On cherche la première ligne correspondant à l'année demandée.
  // (On en a peut-être pas, alors on en prend une supérieure)
  // On lit un paquet de 100 lignes dans le catalogue
  for (int i=0; i<100; i++)
  {
    CurrentPositionY = getCurrentPosition();  // On mémorise la position courante
    readNextLine();
    // on parse la ligne pour lire l'année
    CursorMedia.create(medialine);
    // Si l'année est dans le bon décade: on sort de la boucle
    if (CursorMedia.hasYearBetween(RequestedYear,RangeEnd)) 
    {
      CursorMedia.setSelected(true);
      NextMediaToPlay=CursorMedia:
      break;
    }
  } 

  closeCatalog();

  FirstcurrentPositionY=CurrentPositionY;
  FirstMediaYear  =Field1;
  FirstMediaID    =Field2;
  FirstMediaGenre =Field3;
  FirstMediaRating=Field4;
}

// *******************************************************************************
// Initialisation des recherches de clip pour les genres.
// Cette fonction initialise CurrentPositionG.
// *******************************************************************************
void Catalog::findFirstClipForRequestedGenre(int tuning)
{
    Serial.print(F(" findFirstClipForRequestedGenre ")); Serial.println(RequestedGenre);
    // On ouvre le catalogue au hasard, de façon à trouver une position initiale viable.
    openCatalogAtRandomPosition();
    CurrentPositionG = getCurrentPosition();
    closeCatalog();
    Serial.print(F("  CurrentPositionG="));  Serial.print(CurrentPositionG); Serial.println(F("(new position) "));
    Serial.print(F("  Position of first ")); Serial.print(RequestedGenre);   Serial.print(F(" is ")); Serial.println (CurrentPositionG);
}

// *********************************************************************
// Renvoie TRUE si l'ANNEE du media est dans la bonne période (décade)
// *********************************************************************
/* bool Catalog::isInRange(int year)
{
  return ((year>=RequestedYear) && (year<RangeEnd));
}
*/

// *******************************************************************************
// Renvoie TRUE si le nombre d'étoiles du media est égal au Rating demandé.
// *******************************************************************************
bool Catalog::isAsExpectedRating(String rating)
{
  int Rating = rating.toInt();
  return (Rating == RequestedRating);            // variante: <= Threshold
}
  

// *******************************************************************************
// Renvoie FALSE si le genre du média est egal au Genre demandé.
// Si le genre demandé est "*" alors cad que l'on attend un genre "hors-WhiteList"
//   RequestedGenre = libellé du genre correspondant au tuning
//   genre = libellé du genre du media en cours de lecture.
// *******************************************************************************
bool Catalog::isNotAsExpected(String genre)
{
  //  Serial.println ("isNotAsExpected for "+RequestedGenre);
  if (RequestedGenre=="*") 
    // si le genre attendu est Others, on regarde si le genre lu est dans la Whitelist
    // Si il y est: il faut en chercher un autre. on renvoie donc VRAI.
    {
      Serial.print (" others:"+genre+":"); Serial.println (GenreWhiteList.indexOf(genre));
      return (GenreWhiteList.indexOf(genre)>-1); // -1=>on n'a pas trouvé=> on renvoie FALSE, sinon on renvoie VRAI
    }
  else 
    // si le genre attendu est defini, on le compare au genre lu
    return (!genre.equalsIgnoreCase(RequestedGenre));
}


// *******************************************************************************
// Enleve une Star dans le media courant et dans le fichier index
// *******************************************************************************
void Catalog::removeStar(long clipPosition)
{
  int newValue; // valeur du rating apres décrementation
  // décremente le Rating dans le fichier.
  newValue = writeRemoveStar(clipPosition);
  // Positionne le Rating du Clip En Cours.
  Media_Rating[0] = newValue;
}

// *******************************************************************************
// Ajoute une Star dans le media courant et dans le fichier index
// *******************************************************************************
void Catalog::addStar(long clipPosition)
{
  int newValue; // valeur du rating apres décrementation
  // décremente le Rating dans le fichier.
  newValue = writeAddStar(clipPosition);
  // Positionne le Rating du Clip En Cours.
  Media_Rating[0] = newValue;
}
