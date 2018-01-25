/* *******************************************************************************
* FAVORITES
*
*Cet objet permet d'ajouter ou de retirer des étoiles à un clip du catalogue
******************************************************************************* */

 #include <SdFat.h>
#include "Favorites.h"


// *******************************************************************************
// Constructor
// *******************************************************************************
Favorites::Favorites()
{}

/*
// *******************************************************************************
// Ajoute +1 (max=5) au Rating du clip demandé, dans le fichier Rating.ndx
// *******************************************************************************
void Favorites::addStar(String mediaId)
{
  int    ClipPosition=5;

  // On se positionne sur la ligne du clip
  ClipPosition=this->findID(mediaId);
  if (ClipPosition==NULL) return;
  this->addStar(ClipPosition);
}
*/
  
// *******************************************************************************
// Ajoute +1 (max=5) au Rating du clip demandé, dans le fichier Rating.ndx
// *******************************************************************************
void Favorites::addStar(long clipPosition)
{
  SdFile FichierIndex;
  char   Stars='A';
  
  Serial.print (F("ADDING a Star at ")); Serial.println (clipPosition);
  if (clipPosition==NULL) return;
  
  // On ouvre le fichier (renvoie false si error)
  if (!FichierIndex.open("/Catalog.ndx", O_RDWR))      // renvoie false si error
  {
    // En cas d'erreur d'ouverture du fichier, on sort
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
}
/*
// *******************************************************************************
// Soustrait 1 (min=0) au Rating du clip demandé, dans le fichier Rating.ndx
// *******************************************************************************
void Favorites::removeStar(String mediaId)
{
  int    ClipPosition=5;
  
  // On se positionne sur la ligne du clip
  ClipPosition=this->findID(mediaId);
  if (ClipPosition==NULL) return;
  this->removeStar(ClipPosition);
}
*/

// *******************************************************************************
// Soustrait 1 (min=0) au Rating du clip demandé, dans le fichier Catalog.ndx
// *******************************************************************************
void Favorites::removeStar(long clipPosition)
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
}

/*
// *******************************************************************************
// Renvoie le Rating du clip demandé, issu du le fichier Catalog.ndx
// au format caractère (en cas d'erreur: 'A')
// *******************************************************************************
char Favorites::getClipStars(String mediaId)
{
  SdFile FichierIndex;
  char   Stars='A';
  int    ClipPosition = 5;
  
  // On ouvre le fichier
  if (!FichierIndex.open("/Catalog.ndx"))      // renvoie false si error
  {
    // En cas d'erreur d'ouverture du fichier, on sort
    Serial.println (F("Cannot open Catalog.ndx"));
    return '0';
  }
  // On se positionne sur la ligne du clip
  ClipPosition=findID(mediaId);
  if (ClipPosition==NULL) {FichierIndex.close(); return 'A';}
  
  // On lit le nombre d'etoiles
  Stars = FichierIndex.read();
  // On ferme le fichier
  FichierIndex.close();
  return Stars;
}
*/

