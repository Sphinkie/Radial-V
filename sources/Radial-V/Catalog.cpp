// *******************************************************************************
// Catalog
//
// Cet objet permet de gérer le Catalogue des clips mp3.
// *******************************************************************************

#include <SdFat.h>
#include "Catalog.h"


// *******************************************************************************
// Constructor
// *******************************************************************************
Catalog::Catalog()
{
   Media_Genre="-";
}

// *******************************************************************************
// On initialise le Seed du générateur aléatoire.
// N'a besoin d'être fait qu'une fois, mais pas immédiatement car SD doit être prêt.
// *******************************************************************************
void Catalog::begin()
{
   // On initialise le Seed du générateur aléatoire avec une valeur chaque fois différente.
   randomSeed(analogRead(0));

   // On cherche le nombre maximum, correspondant à la taille du fichier index.
   if (!FichierIndex.open("/Catalog.ndx")) Serial.println(F("Catalog: Cannot open Catalog.ndx"));

   RandomMax = FichierIndex.fileSize();
   FichierIndex.close();
   Serial.print(" taille Catalog.ndx: "); Serial.println(RandomMax);
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
// Parsing des 4 champs d'une ligne de catalogue  (ex: 1956;E76E79B1;Calipso;0; )
// *******************************************************************************
void Catalog::parseFields(String medialine)
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
  RatingPosition = FichierIndex.curPosition()-4;
}

// *******************************************************************************
// Renvoie l'ID qui a été trouvé lors du GetNextClip
// *******************************************************************************
String Catalog::getSelectedClipID()
{
  return Media_ID;
}

// *******************************************************************************
// Renvoie le genre qui a été trouvé lors du GetNextClip
// *******************************************************************************
String Catalog::getSelectedClipGenre()
{
  return Media_Genre;
}

// *******************************************************************************
// Renvoie l'Année qui a été trouvé lors du GetNextClip
// *******************************************************************************
String Catalog::getSelectedClipYear()
{
  return Media_Year;
}

// *******************************************************************************
// Renvoie l'ID qui a été trouvé lors du GetNextClip
// *******************************************************************************
String Catalog::getSelectedClipRating()
{
  return Media_Rating;
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
// "Classique;Blues;Jazz;Folk;Rock n'Roll;Rock;Chanson;Musiques du monde;"
// *********************************************************************
String Catalog::getGenreLabel(int tuning)
{
  if (tuning < 200)  {GenreLength=200; return "*"; }  
  if (tuning < 400)  {GenreLength=200; return "Musiques du monde"; }
  if (tuning < 540)  {GenreLength=140; return "Chanson"; }  
  if (tuning < 590)  {GenreLength=50;  return "Rock"; }  
  if (tuning < 690)  {GenreLength=100; return "Rock n'Roll"; }  
  if (tuning < 790)  {GenreLength=100; return "Folk"; }  
  if (tuning < 850)  {GenreLength=60;  return "Jazz"; }  
  if (tuning < 950)  {GenreLength=100; return "Blues"; }  
  if (tuning < 1024) {GenreLength=74;  return "Classique"; }  

/* Méthode par répartition équitable: non utilisé  
  int    GenreNumber;
  String RequestedGenreFound;
  int    Separ=0;
  int    SeparFin=1;

  GenreNumber       = int(tuning / GenreLength);   // ex: tuning 500 => 500/127.8 = 3.9 => 3eme genre
  CurrentGenreStart = GenreNumber*GenreLength;     // ex: start = 3*127.8=383
  
  // On cherche le Nième ';'
  for (int i=0; i<GenreNumber; i++)
  {
    Separ = GenreWhiteList.indexOf(';',Separ)+1;  
  }
  SeparFin = GenreWhiteList.indexOf(';',Separ);  
  RequestedGenreFound    = GenreWhiteList.substring(Separ,SeparFin);
  if (RequestedGenreFound.length()==0) RequestedGenreFound="*";
*/
  
  return "*";
}


// *********************************************************************
// Renvoie le RATING correspondant à la position du bouton TUNE
// *********************************************************************
int Catalog::getStarsValue(int value)
{
  if (value < 500)  {return 5; }  /* 000..500  : 5 étoiles   */
  if (value < 600)  {return 4; }  /* 500..600  : 4 étoiles   */  
  if (value < 700)  {return 3; }  /* 600..700  : 3 étoiles   */
  if (value < 850)  {return 2; }  /* 700..900  : 2 étoiles   */
  if (value < 980)  {return 1; }  /* 800..980  : 1 étoile    */
  else  {return 0; }              /* 980..1023 : sans étoile */
}

// *********************************************************************
// Renvoie l'ANNEE correspondant à la position du bouton TUNE
// *********************************************************************
int Catalog::getYearValue(int tuning)
{
/*  if (tuning < 370)          {RangeStart=2000; RangeEnd=2050; return (2000+ (tuning-950));      }
  if (tuning < 500)          {RangeStart=1980; RangeEnd=2000; return (1980+ (tuning-800) *0.1); }  //1980..2000
  if (tuning < 600)          {RangeStart=1970; RangeEnd=1980; return (1970+ (tuning-700) *0.1); }  //1970..1980
  if (tuning < 700)          {RangeStart=1960; RangeEnd=1970; return (1960+ (tuning-600) *0.1); }  //1960..1970
  if (tuning < 770)          {RangeStart=1950; RangeEnd=1960; return (1950+ (tuning-500) *0.1); }  //1950..1960
  if (tuning < 840)          {RangeStart=1940; RangeEnd=1950; return (1940+ (tuning-400) *0.1); }  //1940..1950
  if (tuning < 900)          {RangeStart=1900; RangeEnd=1940; return (1900+ (tuning-300) *0.4); }  //1900..1940
  if (tuning < 950)          {RangeStart=1800; RangeEnd=1900; return (1800+ (tuning-200));}        //1800..1900
  if (tuning <1000)          {RangeStart=1700; RangeEnd=1800; return (1700+ (tuning-100));}        //1700..1800
  if (tuning <1024)          {RangeStart=0;    RangeEnd=1700; return (      (tuning    ) *170);}   //   0..1700
*/
  if (tuning < 370)          {RangeStart=2000; RangeEnd=2050; return map(tuning, 370,   0,RangeStart,RangeEnd);    }
  if (tuning < 500)          {RangeStart=1980; RangeEnd=2000; return map(tuning, 500, 370,RangeStart,RangeEnd);    }
  if (tuning < 600)          {RangeStart=1970; RangeEnd=1980; return map(tuning, 600, 500,RangeStart,RangeEnd);    }
  if (tuning < 700)          {RangeStart=1960; RangeEnd=1970; return map(tuning, 700, 600,RangeStart,RangeEnd);    }
  if (tuning < 770)          {RangeStart=1950; RangeEnd=1960; return map(tuning, 770, 700,RangeStart,RangeEnd);    }
  if (tuning < 840)          {RangeStart=1940; RangeEnd=1950; return map(tuning, 840, 770,RangeStart,RangeEnd);    }
  if (tuning < 900)          {RangeStart=1900; RangeEnd=1940; return map(tuning, 900, 840,RangeStart,RangeEnd);    }
  if (tuning < 950)          {RangeStart=1800; RangeEnd=1900; return map(tuning, 950, 900,RangeStart,RangeEnd);    }
  if (tuning <1000)          {RangeStart=1700; RangeEnd=1800; return map(tuning,1000, 950,RangeStart,RangeEnd);    }
  if (tuning <1024)          {RangeStart=0;    RangeEnd=1700; return map(tuning,1024,1000,RangeStart,RangeEnd);    }

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
  String  LineRead;
  bool    FileAccessOK;

  // On ouvre le fichier
  FileAccessOK = this->openCatalogAtPosition(5);
  // En cas d'erreur d'ouverture du fichier, on renvoie "NOISE.MP3"
  if (!FileAccessOK) return ("NOISE");
  
  // On lit une ligne au hasard dans le fichier
  LineRead = this->readRandomLine();
  this->closeCatalog(); 
  if (LineRead=="ERROR") {return "NOISE";}    
  if (LineRead=="EOF")   {return "NOISE";}
  
  // Serial.print(F("  line read: ")); Serial.println (LineRead);
  
  // on parse la ligne du media trouvé pour extraire l'ID
  this->parseFields(LineRead);
  LastMedia_ID = Media_ID;
  Media_ID     = Field2;

  // Si on est tombé 2 fois sur le même ID, on met du Noise
  if (LastMedia_ID==Media_ID) Media_ID="NOISE";

  // On stocke les infos du clip trouvé
  Media_Rating = Field4;
  Media_Genre  = Field3;
  Media_Year   = Field1;   
  // On retourne l'ID du media trouvé
  return Media_ID;
}


// *******************************************************************************
// Renvoie l'ID du Clip suivant dans l'index, correspondant au genre demandé.
// On commence la recherche à partir de CurrentPosition (qui est l'emplacement du dernier clip joué,
// ou du début, si on a fait un initSearch.
// *******************************************************************************
String Catalog::selectClipForRequestedGenre(int tuning)
{
  bool   FileAccessOK;
  char   line[MAX_LG_LINE];            // ligne lue dans le fichier index
  String medialine;
  
  RequestedGenre = this->getGenreLabel(tuning); // La valeur textuelle du genre demandé
  Serial.println ("  selectClipForRequestedGenre: "+RequestedGenre);
    
  // On se positionne a la dernière position utilisée pour Genre.
  FileAccessOK = this->openCatalogAtPosition(CurrentPositionG);
  // En cas d'erreur d'ouverture du fichier, on renvoie "NOISE.MP3"
  if (!FileAccessOK) return ("NOISE");

  // On lit des lignes jusqu'à ce qu'on trouve une ligne du genre demandé
  do
  {
    // On lit une ligne
    medialine = this->readNextLine();
    if (medialine=="ERROR") {this->closeCatalog(); return "NOISE";}    
    if (medialine=="EOF")   {this->closeCatalog(); this->findFirstClipForRequestedGenre(1); return "NOISE";}
    // Serial.print (F("  line read in Catalog.ndx: ")); Serial.println (medialine);
    CurrentPositionG = FichierIndex.curPosition();  // On mémorise la position courante
    // on parse la ligne pour connaitre le genre que l'on compare au genre attendu
    this->parseFields(medialine);
    // tant que le genre lu n'est pas conforme au genre attendu...
  } while (this->isNotAsExpected(Field3));      
  Serial.println (F(" found a match! "));
  
  this->closeCatalog(); 

  // On mémorise les informations sur le media touvé
  Media_Year  = Field1;
  Media_ID    = Field2;   // this->parseMediaID(String(line));
  Media_Genre = Field3;   // this->parseGenre(String(line));
  Media_Rating= Field4;

  // Retourne l'ID du media
  return Media_ID;
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
  medialine = this->readNextLine();
  if (medialine=="ERROR") {FichierIndex.close(); return "NOISE";}    
  if (medialine=="EOF")   {FichierIndex.close(); return "NOISE";}

  Serial.print (F("  line read: ")); Serial.print (medialine);
  CurrentPositionY  =FichierIndex.curPosition();  // On mémorise la position courante
  FichierIndex.close();

  this->parseFields(medialine);
  // On verifie si le YEAR lu est toujours bien dans la période musicale demandée
  if (Field3.toInt()>RangeEnd)
  {
    // Si on déborde, alors on rewinde.
    CurrentPositionY=FirstcurrentPositionY;
    Media_Year  = FirstMediaYear;
    Media_ID    = FirstMediaID;
    Media_Genre = FirstMediaGenre;
    Media_Rating= FirstMediaRating;
  }
  else
  {
    // On memorise l'ID Media trouvé
    Media_Year  = Field1;
    Media_ID    = Field2;
    Media_Genre = Field3;
    Media_Rating= Field4;
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

  FileAccessOK = this->openCatalogAtPosition(5);
  // En cas d'erreur d'ouverture du fichier, on renvoie "NOISE.MP3"
  if (!FileAccessOK) return ("NOISE");
  
  // On lit une ligne au hasard dans le fichier
  medialine = this->readRandomLine();
  if (medialine=="ERROR") {FichierIndex.close(); return "NOISE";}    
  if (medialine=="EOF")   {FichierIndex.close(); return "NOISE";}
  Serial.print (F(" line read: ")); Serial.print (medialine);
  this->parseFields(medialine);

  // Si ce clip n'a pas assez d'étoiles, alors on on lit la ligne suivante
  while (!this->isAsExpectedRating(Field4))
  {
        medialine=this->readNextLine();
        if (medialine=="ERROR")  {FichierIndex.close(); return "NOISE";}  
        if (medialine=="EOF")    {FichierIndex.close(); return "NOISE";}  
        this->parseFields(medialine);
  } 

  // On memorise l'ID Media trouvé
  Media_Year       = Field1;
  Media_ID         = Field2;
  Media_Genre      = Field3;
  Media_Rating     = Field4;

  // on envoie l'ID du media trouvé
  FichierIndex.close();
  return (Media_ID);
}

// *******************************************************************************
// Ouvre le fichier Catalog.ndx, en gérant les cas d'erreur.
// *******************************************************************************
bool Catalog::openCatalogAtPosition(long pos)
{
  bool FileAccessOK;
  
  FileAccessOK = FichierIndex.open("/Catalog.ndx");      // on ouvre le fichier Catalog
  if (!FileAccessOK)
  {
    // en cas d'erreur d'ouverture du fichier, on renvoie "NOISE.MP3"
    Serial.println (F("Cannot open Catalog.ndx"));
    return (false);
  }
  
  // On se positionne dans l'index à la derniere position connue
  Serial.print(F("  Catalog.ndx: going to position ")); Serial.println(pos);
  FileAccessOK = FichierIndex.seekSet(pos);
  if (!FileAccessOK)
  {
    Serial.print(F("Catalog.ndx: Cannot go to position ")); Serial.println(pos);
    FichierIndex.close();
    return (false);
  }
  return true;
}

// *******************************************************************************
// Ferme le fichier Catalog.ndx.
// *******************************************************************************
void Catalog::closeCatalog()
{
  FichierIndex.close();
}

// *******************************************************************************
// Lit une ligne au hasard dans le fichier.
// Le FichierIndex est ouvert préalablement.
// Renvoie la ligne, ou "EOF" ou "ERROR"
// *******************************************************************************
String Catalog::readRandomLine()
{
   char         line[MAX_LG_LINE];         // ligne lue dans le fichier
   unsigned int RandomNb;         // Numéro aléatoire entre 1 et taille
   int          Lg=0;
   String       medialine;

  RandomNb   = random(RandomMax)+1;   // random(Max) renvoie un nombre aléatoire entre 0 et Max-1
  Serial.print("  read random line, number "); Serial.print (RandomNb); Serial.print (" out of "); Serial.println (RandomMax); 
   
  // On se positionne sur un octet au hasard dans l'index
  if (!FichierIndex.seekSet(RandomNb))
  {
    Serial.println (F("Ratings.txt: Cannot go to position ")); Serial.println(RandomNb);
    return ("ERROR");
  }
  
  //On lit la fin de la ligne en cours (généralement tronquée, puisqu'on s'est placé au hasard dans le fichier)
  Lg = FichierIndex.fgets(line,MAX_LG_LINE);
  if (Lg==-1) return ("ERROR");      // Erreur de lecture
  if (Lg==0)  return ("EOF");      // la ligne lue est vide ou EOF
  // Serial.print (" positioned at : "); Serial.println (line);
  
  // On lit la ligne suivante
  Lg = FichierIndex.fgets(line,MAX_LG_LINE);
  if (Lg==-1) return ("ERROR");      // Erreur de lecture
  if (Lg==0)  return ("EOF");      // la ligne lue est vide ou EOF

  medialine=String(line);
  medialine.trim();
  return medialine;
}

// *******************************************************************************
// On lit la ligne suivante du fichier
// Le FichierIndex est ouvert préalablement.
// *******************************************************************************
String Catalog::readNextLine()
{
  char   Line[MAX_LG_LINE];         // ligne lue dans le fichier
  String Medialine;
   
  // On lit la ligne suivante
  int Lg = FichierIndex.fgets(Line,MAX_LG_LINE);
  if (Lg==-1) return ("ERROR");    // Erreur de lecture
  if (Lg==0)  return ("EOF");      // la ligne lue est vide ou EOF

  Medialine=String(Line);
  Medialine.trim();
  return Medialine;
}


// *******************************************************************************
// Initialisation des recherches de clip pour une année donnée.
// Il faut appeler cette méthode lorsque l'année demandée change, ou que l'on vient de basculer sur le mode "YEAR".
// Cette fond parcourt le Catalogue depuis le début jusqu'à trouver une année qui correspond à l'année demandée.
// Cette fonction initialise FirstcurrentPositionY et CurrentPositionY.
// Cette fonctione est un peu longue: voir si on peut l'optimiser...
// *******************************************************************************
void Catalog::findFirstClipForRequestedYear()
{
  char   Line[MAX_LG_LINE];            // ligne lue dans le fichier catalogue
  int    Lg;
  String medialine;

  // on se positionne au debut du Catalogue
  Serial.print(F(" findFirstClipForRequestedYear ")); Serial.println(RequestedYear);
  CurrentPositionY  =5;                      // Au debut du fichier index, il y a quelques octets inutiles. En dessous de 5, le programme plante.

  // on ouvre le fichier Catalogue 
  if (!FichierIndex.open("/Catalog.ndx"))      Serial.println (F("Cannot open Catalog.ndx"));
    
  // On se positionne au debut du Catalogue
  FichierIndex.seekSet(5);

  // On cherche la première ligne correspondant à l'année demandée.
  // (On en a peut-être pas, alors on en prend une supérieure)
  do
  {
    CurrentPositionY  =FichierIndex.curPosition();  // On mémorise la position courante
    Lg = FichierIndex.fgets(Line,MAX_LG_LINE);         // On lit une ligne
    if (Lg==-1) {Serial.println (F("Cannot read Catalog.ndx")); break;}     // Erreur de lecture
    if (Lg==0 ) {Serial.println (F("End of Catalog"));          break;}     // Fin de fichier - EOF
    if (Lg <10) {Serial.println (F("line too short in Catalog.ndx")); Serial.println(Lg); Serial.println(Line);    continue;}     // ligne trop courte
      
    // Serial.print (" rewinding to line "); Serial.print (currentPositionY); Serial.print (F(" in Catalog.ndx: line read=")); Serial.println(line); 
    medialine=String(Line);
    medialine.trim();
    // on parse la ligne pour lire l'année
    this->parseFields(medialine);
  } while (!isInRange(Field1.toInt()));

  FichierIndex.close();

  FirstcurrentPositionY=CurrentPositionY;
  FirstMediaYear  =Field1;
  FirstMediaID    =Field2;
  FirstMediaGenre =Field3;
  FirstMediaRating=Field4;
}

// *******************************************************************************
// Initialisation des recherches de clip pour les genres.
// Cette fonction initialise CurrentPositionG.
// Cette position initiale dépend du Tuning, ainsi on ne commence par toujours par le meme premier clip du genre.
// *******************************************************************************
void Catalog::findFirstClipForRequestedGenre(int tuning)
{
  char   Line[MAX_LG_LINE];            // ligne lue dans le fichier catalogue

    Serial.print(F(" findFirstClipForRequestedGenre ")); Serial.println(RequestedGenre);
    // CurrentPositionG  =5;    
    // On se positionne entre [5 .. TailleCatalog]  (TailleCatalog = randomMax)
    // en fonction d'un current tuning entre [Gdeb .. Gfin]
/*    
 *     Algo:
 *     Pour le genre G, on a un tuning compris   entre Gdeb et Gfin.
 *     La Position 'f' dans le fichier en % sera entre   0  et  1 
 *     f = (tuning-Gdeb)/(Gfin-Gdeb) = (tuning-Gdeb)/(GenreLength)
 */
    float f = float(tuning-CurrentGenreStart)/GenreLength;
    Serial.print(F("  f=")); Serial.print(int(f*100)); Serial.println(F("% of file"));
    unsigned int p = max(5,f*RandomMax - 100);  // on prend une marge de 100 chars pour ne pas être trop près de la fin du catalogue
    Serial.print(F("  p=")); Serial.print(p); Serial.println(F("(new planned position)"));
    // on se positionne à p, et on lit une ligne bidon, de façon à trouver une position initiale viable.
    FichierIndex.open("/Catalog.ndx");
    FichierIndex.seekSet(p);
    FichierIndex.fgets(Line,MAX_LG_LINE);
    CurrentPositionG  =FichierIndex.curPosition();
    Serial.print(F("  CurrentPositionG=")); Serial.print(CurrentPositionG); Serial.println(F("(new position) "));
    FichierIndex.close();

    Serial.print(F("  Position of first ")); Serial.print(RequestedGenre); Serial.print(F(" is ")); Serial.println (CurrentPositionG);
    
}

// *********************************************************************
// Renvoie TRUE si l'ANNEE du media est dans la bonne période (décade)
// *********************************************************************
bool Catalog::isInRange(int year)
{
  return ((year>=RequestedYear) && (year<RangeEnd));
}


// *******************************************************************************
// Renveio TRUE si le nombre d'étoiles du media est égal au Rating demandé.
// *******************************************************************************
bool Catalog::isAsExpectedRating(String rating)
{
  int Rating = rating.toInt();
  return (Rating == RequestedRating);            // variante: <= Threshold
}
  

// *******************************************************************************
// Renvoie FALSE si le genre du média est egal genre demandé.
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
// Ajoute +1 (max=5) au Rating du clip demandé, dans le fichier Catalog.ndx
// *******************************************************************************
void Catalog::writeAddStar(long clipPosition)
{
  SdFile FichierIndex;
  char   Stars='A';
  
  Serial.print (F("ADDING a Star at ")); Serial.println (clipPosition);
  if (clipPosition==NULL) return;
  
  // On ouvre le fichier (renvoie false si error)
  if (!FichierIndex.open("/Catalog.ndx", O_RDWR))      // renvoie False en cas d'erreur
  {
    // En cas d'erreur d'ouverture du fichier, on sort.
    Serial.println (F("Cannot open Catalog.ndx"));
    return;
  }
  
  // On se positionne sur la ligne du clip
  FichierIndex.seekSet(clipPosition);
  
  // On lit le nombre d'etoiles (1 octet)
  Stars = FichierIndex.read();
  Serial.print (F(" I have read a byte:")); Serial.print(Stars);
  // On incrémente
  if (++Stars >'5') Stars='5'; 
  if (Stars   <'0') Stars='0';
  // On ecrit le nouveau nombre d'étoiles
  FichierIndex.seekSet(clipPosition);
  FichierIndex.print(Stars);
  Serial.print (F(" and replaced with ")); Serial.println(Stars);

  // On vérifie (pour le debug)
  FichierIndex.seekSet(clipPosition-12);
  Serial.print (F(" Debug end of line (after update): "));
  for (int i=0; i<14; i++) 
    {
      char Debug = FichierIndex.read(); 
      Serial.print(Debug);
    }
  Serial.println(); 
  
  // On ferme le fichier
  FichierIndex.close();
  
  // Positionne le Rating du Clip En Cours.
  Media_Rating[0] = Stars;
}


// *******************************************************************************
// Soustrait 1 (min=0) au Rating du clip demandé, dans le fichier Catalog.ndx
// *******************************************************************************
void Catalog::writeRemoveStar(long clipPosition)
{
  SdFile FichierIndex;
  char   Stars='A';
  
  Serial.print (F("REMOVING a Star at ")); Serial.println (clipPosition);
  if (clipPosition==NULL) return;

  // On ouvre le fichier
  if (!FichierIndex.open("/Catalog.ndx", O_RDWR))      // renvoie false si error
  {
    // En cas d'erreur d'ouverture du fichier, on sort
    Serial.println (F("Cannot open Catalog.ndx"));
    return;
  }

  // On se positionne sur la ligne du clip
  FichierIndex.seekSet(clipPosition);
  
  // On lit le nombre d'etoiles
  Stars = FichierIndex.read();
  Serial.print (F(" I have read byte ")); Serial.print(Stars);
  // On décrémente
  if (--Stars < '0') Stars='0';
  if (Stars   >'5') Stars='5';
  // On ecrit le nouveau nombre d'étoiles
  FichierIndex.seekSet(clipPosition);
  FichierIndex.print(Stars);
  Serial.print (F(" and replaced with ")); Serial.println(Stars);
  
  // On vérifie (pour le debug)
  FichierIndex.seekSet(clipPosition-12);
  Serial.print (F(" Debug end of line (after update): "));
  for (int i=0; i<14; i++) 
    {
      char Debug = FichierIndex.read(); 
      Serial.print(Debug);
    }
  Serial.println(); 
  
  // On ferme le fichier
  FichierIndex.close();
  // Positionne le Rating du Clip En Cours.
  Media_Rating[0] = Stars;
}

// *******************************************************************************
// Ecrit le Rating du clip demandé, dans le fichier Catalog.ndx
// (on convertit les ints 0..5 en chars '0'..'5' 
// *******************************************************************************
void Catalog::writeRating(int rating, long clipPosition)
{
  SdFile FichierIndex;
  
  Serial.print (F("writing Rating at ")); Serial.println (clipPosition);
  if (clipPosition==NULL) return;
  
  // On ouvre le fichier (renvoie false si error)
  if (!FichierIndex.open("/Catalog.ndx", O_RDWR))      // renvoie False en cas d'erreur
  {
    // En cas d'erreur d'ouverture du fichier, on sort.
    Serial.println (F("Cannot open Catalog.ndx"));
    return;
  }
  
  // On se positionne sur la ligne du clip
  FichierIndex.seekSet(clipPosition);
  // On ecrit 1 octet
  char stars = char(rating +'0');
  FichierIndex.print(stars);

  // On vérifie (pour le debug)
  FichierIndex.seekSet(clipPosition-12);
  Serial.print (F(" Debug end of line (after update): "));
  for (int i=0; i<14; i++) 
    {
      char Debug = FichierIndex.read(); 
      Serial.print(Debug);
    }
  Serial.println(); 
  
  // On ferme le fichier
  FichierIndex.close();
}

// *******************************************************************************
// Lit le Rating du clip demandé, dans le fichier Catalog.ndx
// *******************************************************************************
int Catalog::readRating(long clipPosition)
{
  SdFile FichierIndex;
  char   Stars='A';
  
  Serial.print (F("reading Rating at ")); Serial.println (clipPosition);
  if (clipPosition==NULL) return;
  
  // On ouvre le fichier (renvoie false si error)
  if (!FichierIndex.open("/Catalog.ndx", O_RDWR))      // renvoie False en cas d'erreur
  {
    // En cas d'erreur d'ouverture du fichier, on sort.
    Serial.println (F("Cannot open Catalog.ndx"));
    return 0;
  }
  
  // On se positionne sur la ligne du clip
  FichierIndex.seekSet(clipPosition);
  // On lit 1 octet
  Stars = FichierIndex.read();


  // On vérifie (pour le debug)
  FichierIndex.seekSet(clipPosition-12);
  Serial.print (F(" Debug end of line (after update): "));
  for (int i=0; i<14; i++) 
    {
      char Debug = FichierIndex.read(); 
      Serial.print(Debug);
    }
  Serial.println(); 
  
  // On ferme le fichier
  FichierIndex.close();
  return (Stars-'0');  // renvoie un entier
}
