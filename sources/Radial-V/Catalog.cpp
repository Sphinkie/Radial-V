/* *******************************************************************************
 *  Gestion du catalogue des MP3
 ********************************************************************************/
#include "Arduino.h"
#include "Catalog.h"
#include "Plexiglass.h"
#include "Media.h"


// *******************************************************************************
// Constructor (avec Classe de base = CatalogFile)
// *******************************************************************************
Catalog::Catalog() : CatalogFile()
{
  NoiseMedia.fillWith("0000;NOISE;*;0;");
  SearchInProgress=false;
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
  Plexi.setTuning(tuning);
/*  
  RequestedGenre = Plexi.Genre;   // La valeur textuelle du genre demandé
  RequestedYear  = Plexi.Year;    // La valeur textuelle de l'année demandée
  RequestedRating= Plexi.Rating;  // La valeur textuelle du rating demandé
  */
}

// *******************************************************************************
// Renvoie les infos du clip qui a été trouvé lors du GetNextClip
// *******************************************************************************
String Catalog::getSelectedClipID()    {  return CurrentMedia.getID();}
String Catalog::getSelectedClipGenre() {  return CurrentMedia.getGenre();}
String Catalog::getSelectedClipYear()  {  return String(CurrentMedia.getYear());}
String Catalog::getSelectedClipRating(){  return String(CurrentMedia.getRating());}


// *******************************************************************************
// MODE RANDOM: Sélectionne un clip au hasard, tiré dans le catalogue.
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
// MODE GENRE:
//          Step 1: on se positionne sur un media random du catalogue (1 appel)
//          Step 2: à partir de là, on cherche un media avec le RequestedGenre (N appels)
// *******************************************************************************
// Initialisation des recherches de clip pour les genres.
// Cette fonction initialise CurrentPositionG.
// *******************************************************************************
void Catalog::initSearchForRequestedGenre()
{
    Serial.print(F(" initSearchForRequestedGenre "));
    // On ouvre le catalogue au hasard, de façon à trouver une position initiale viable.
    openCatalogAtRandomPosition();
    CurrentPositionG = getCurrentPosition();
    closeCatalog();
    // On peut demarrer la recherche
    SearchInProgress=true;
    Serial.print(F("  CurrentPositionG="));  Serial.print(CurrentPositionG); Serial.println(F("(new position) "));
}
// *******************************************************************************
// Recherche un media de RequestedGenre à partir de la deniere position
// Positionne NextMediaToPlay une fois le media trouvé.
// *******************************************************************************
void Catalog::searchClipForRequestedGenre()
{
  bool   FileAccessOK;
  String medialine;

  // Si aucune recherche n'est demandée ou en cours: on sort.
  if (!SearchInProgress) return;
  
  RequestedGenre = Plexi.Genre; // La valeur textuelle du genre demandé
  Serial.println ("  searchClipForRequestedGenre: "+RequestedGenre);
    
  // On se positionne a la dernière position utilisée pour Genre.
  FileAccessOK = this->openCatalogAtPosition(CurrentPositionG);
  // En cas d'erreur d'ouverture du fichier, on renvoie "NOISE.MP3"
  if (!FileAccessOK) return ("NOISE");

  // On lit des lignes jusqu'à ce qu'on trouve une ligne du genre demandé (ou pas)
  for (int i=0; i<100; i++)
  {
     // On lit une ligne
     medialine = this->readNextLine();
     if (medialine=="ERROR") {NextMediaToPlay=NoiseMedia; break;}    
     if (medialine=="EOF")   {this->findFirstClipForRequestedGenre(1); NextMediaToPlay=NoiseMedia; break;}
     // Serial.print (F("  line read in Catalog.ndx: ")); Serial.println (medialine);
     CurrentPositionG = getCurrentPosition();  // On mémorise la position courante
     CursorMedia.fillWith(medialine);
     // Si on a trouvé un Media avec le bon GENRE, on le mémorise et on sort.
     if (CursorMedia.isGenre(Plexi.Genre))
     {
        CursorMedia.setNextMediaPosition(CurrentPositionG);
        NextMediaToPlay=CursorMedia;
        SearchInProgress=false; // La recherche est terminée
        break;
     }
  } 
  this->closeCatalog(); 
}

/* *******************************************************************************
 * MODE YEAR:
 *          Step 1: on se positionne sur le premier media du catalogue (1 appel)
 *          Step 2: à partir de là, on cherche un media avec le RequestedYear (N appels)
 *          (Le premier Step2 va demander N appels, les suivants: 1 appel)
 *  *******************************************************************************
 * Initialisation des recherches de clip pour une année donnée.
 * Il faut appeler cette méthode lorsque l'année demandée change, ou que l'on vient de basculer sur le mode "YEAR".
 * ******************************************************************************* */
void Catalog::initSearchForRequestedYear()
{
  Serial.print(F(" initSearchForRequestedYear ")); Serial.println(Plexi.Year);
  // on se positionne au debut du Catalogue
  openCatalogAtPosition();
  CurrentPositionY = getCurrentPosition();  // On mémorise la position courante
  closeCatalog();
  // On peut demarrer la recherche
  SearchInProgress=true;
  Serial.print(F("  CurrentPositionY="));  Serial.print(CurrentPositionY); Serial.println(F("(new position) "));
}
/* *******************************************************************************
 * Renvoie le clip suivant dans l'index, correspondant à une periode allant 
 * de l'année sélectionnée à la fin de la période.
 * La fin de la période est définie dans getYearValue().
 * L'index (ordonné) Catalog.ndx permet d'avancer d'année en année.
 * ******************************************************************************* */
void Catalog::searchClipForRequestedYear()
{
  bool   FileAccessOK;
  String medialine;
  long   mediaPosition;
 
  Serial.print(F("  selectClipForRequestedYear: ")); Serial.println(Plexi.Year);

  FileAccessOK = this->openCatalogAtPosition(CurrentPositionY);
  // En cas d'erreur d'ouverture du fichier, on renvoie "NOISE.MP3"
  if (!FileAccessOK) return ("NOISE");

  // On cherche la première ligne correspondant à la periode demandée.
  // On lit un paquet de 100 lignes dans le catalogue
  for (int i=0; i<100; i++)
  {
    CurrentPositionY = getCurrentPosition();  // On mémorise la position courante
    readNextLine();
    if (medialine=="ERROR") {closeCatalog(); return "NOISE";}    
    if (medialine=="EOF")   {closeCatalog(); return "NOISE";}
    Serial.print (F("  line read: ")); Serial.print (medialine);
    // on parse la ligne pour lire l'année
    CursorMedia.fillWith(medialine);
    // Si l'année est dans la bonne décade: on sort de la boucle
    if (CursorMedia.hasYearBetween(Plexi.Year, Plexi.RangeEnd)) 
    {
      CursorMedia.setSelected(true);
      FirstMediaForRequestedYear=CursorMedia;
      FirstMediaForRequestedYear.setNextMediaPosition(CurrentPositionY);
      break;
    }
    // Si on a depassé la fin ed la période, alors on rewinde.
    if (Cursor.getYear() > Plexi.RangeEnd)
    {
      CurrentPositionY = FirstMediaForRequestedYear.getNextMediaPosition();
      NextMediaToPlay  = FirstMediaForRequestedYear;
    }
  } 
  closeCatalog();
}


// *******************************************************************************
// On renvoie un clip au hasard, mais ayant le nombre d'étoiles demandé.
// *******************************************************************************
String Catalog::selectClipForRequestedRating()
{
  String medialine;
  bool   FileAccessOK;

  Serial.print(F("  selectClipForRequestedRating ")); Serial.println(RequestedRating);

  // On lit une ligne au hasard dans le fichier
  FileAccessOK = this->openCatalogAtRandomPosition();
  // En cas d'erreur d'ouverture du fichier, on renvoie "NOISE.MP3"
  if (!FileAccessOK) return ("NOISE");
  
  for (int i=0; i<100; i++)
  {
        medialine=this->readNextLine();
        Serial.print (F(" line read: ")); Serial.print (medialine);
        if (medialine=="ERROR")  {closeCatalog(); return "NOISE";}  
        if (medialine=="EOF")    {closeCatalog(); return "NOISE";}  
        CursorMedia.fillWith(medialine);
        // Si ce clip n'a pas assez d'étoiles, alors on on lit la ligne suivante
        if (CursorMedia.getRating()==RequestedRating) 
        {
          break;
        }
  } 
  closeCatalog();

  return ("");
}


// *******************************************************************************
// Enleve une Star dans le media courant et dans le fichier index
// *******************************************************************************
void Catalog::removeStar()
{
  int newRatingValue; // valeur du rating apres décrementation
  // décremente le Rating dans le fichier.
  newRatingValue = writeRemoveStar(CurrentMedia.getRatingPosition());
  // Positionne le Rating du Clip En Cours.
  CurrentMedia.setRating(newRatingValue);
}

// *******************************************************************************
// Ajoute une Star dans le media courant et dans le fichier index
// *******************************************************************************
void Catalog::addStar()
{
  int newRatingValue; // valeur du rating apres décrementation
  // décremente le Rating dans le fichier.
  newRatingValue = writeAddStar(CurrentMedia.getRatingPosition());
  // Positionne le Rating du Clip En Cours.
  CurrentMedia.setRating(newRatingValue);
}
