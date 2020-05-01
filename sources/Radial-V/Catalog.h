/* *******************************************************************************
 *  Gestion du fichier catalogue des MP3
 ********************************************************************************/

#ifndef CATALOGCLASS_H_INCLUDED
#define CATALOGCLASS_H_INCLUDED

#include "CatalogFile.h"
#include "Plexiglass.h"
#include "Media.h"



// La classe Catalog dérive de la classe CatalogFile (qui contient les primitives de lecture/ecriture dans le fichier de la carte SD
class Catalog:CatalogFile
{
    public:
        Catalog();
        // initialisations
        void   initialize();
        void   setNewRequestedValues(int tuning);
        void   initSearchForRequestedYear();
        void   initSearchForRequestedGenre();
        // selection d'un clip
        String selectRandomClip();
        void   searchClipForRequestedGenre();
        void   searchClipForRequestedYear();
        String selectClipForRequestedRating();
        // recupération des infos du clip sélectionné
        String getSelectedClipID();
        String getSelectedClipGenre();
        String getSelectedClipYear();
        String getSelectedClipRating();

        void   removeStar();
        void   addStar();
              


    //variables:
    public:
        String        RequestedGenre;        // Le Genre demandé par bouton Tuning
        int           RequestedRating;       // Le Rating demandé par bouton Tunnig
        int           RequestedYear;         // L'Année demandée par bouton Tuning (ex: 1964)
        // Face Avant
        Plexiglass    Plexi;


    private:
        Media         NoiseMedia;
        Media         CursorMedia;
        Media         NextMediaToPlay;
        Media         CurrentMedia;
        Media         FirstMediaForRequestedYear;   // Premier Media ayant la date demandée

		

        // Les curseurs dans le catalogue
        long          FirstcurrentPositionY; // curseur de debut de décade (mode YEAR)
        long          CurrentPositionY;      // curseur pour le mode YEAR
        long          CurrentPositionG;      // curseur pour le mode GENRE
        long          RatingPosition;        // curseur pour le mode RATING
        bool          SearchInProgress;

};


#endif // CATALOGCLASS_H_INCLUDED
