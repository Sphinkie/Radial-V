/* *******************************************************************************
 *  Gestion du fichier catalogue des MP3
 ********************************************************************************/

#ifndef CATALOGCLASS_H_INCLUDED
#define CATALOGCLASS_H_INCLUDED

#include "CatalogFile.h"
#include "Media.h"

#define MAX_TUNING    1023        // Les entrées Analog renvoient une valeur entre 0 et 1023


// La classe Catalog dérive de la classe CatalogFile (qui contient les primitives de lecture/ecriture dans le fichier de la carte SD
class Catalog:CatalogFile
{
    public:
        Catalog();
        // initialisations
        void   initialize();
        void   setNewRequestedValues(int tuning);
        void   findFirstClipForRequestedYear();
        void   findFirstClipForRequestedGenre(int tuning);
        // selection d'un clip
        String selectRandomClip();
        String selectClipForRequestedGenre(int tuning);
        String selectClipForRequestedYear();
        String selectClipForRequestedRating();
        // recupération des infos du clip sélectionné
        String getSelectedClipID();
        String getSelectedClipGenre();
        String getSelectedClipYear();
        String getSelectedClipRating();
        long   getRatingPosition();
        void   removeStar(long clipPosition);
        void   addStar(long clipPosition);
              
    private:

        String getGenreLabel(int value);
        int    getYearValue(int tuning);
        int    getStarsValue(int value);
        bool   isInRange(int year);
        bool   isNotAsExpected(String mediagenre);
        bool   isAsExpectedRating(String rating);

        // debugage
        void   debugGenre();
        void   debugYear();

    //variables:
    public:
        String        RequestedGenre;        // Le Genre demandé par bouton Tuning
        int           RequestedRating;       // Le Rating demandé par bouton Tunnig
        int           RequestedYear;         // L'Année demandée par bouton Tuning (ex: 1964)
        int           RangeStart;            // Année demandée: Début de la période (ex: 1960)
        int           RangeEnd;              // Année demandée: Fin de la période (ex: 1970)

    private:
        // Infos sur le dernier Media valide trouvé
        // String        LastMedia_ID;   // sert à eviter de tomber deux fois de suite sur le même ID

        Media         NextMediaToPlay;
        Media         CursorMedia;


        // Infos sur les genres apparaissant sur la face avant (White List)
        const String  GenreWhiteList="Classique;Blues;Jazz;Folk;Rock n'Roll;Rock;Chanson;Musiques du monde;";  // Ne pas oublier le ; final
        float         GenreLength;
        int           CurrentGenreStart;
        // Infos sur le premier Media ayant la date demandée
        String        FirstMediaID;
        String        FirstMediaYear;
        String        FirstMediaGenre;
        String        FirstMediaRating;

        // Les curseurs dans le catalogue
        long          FirstcurrentPositionY; // curseur de debut de décade (mode YEAR)
        long          CurrentPositionY;      // curseur pour le mode YEAR
        long          CurrentPositionG;      // curseur pour le mode GENRE
        long          RatingPosition;        // curseur pour le mode RATING

};


#endif // CATALOGCLASS_H_INCLUDED
