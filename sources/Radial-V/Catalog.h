/* *******************************************************************************
 *  Gestion du fichier catalogue des MP3
 ********************************************************************************/

#ifndef CATALOGCLASS_H_INCLUDED
#define CATALOGCLASS_H_INCLUDED

#define MAX_TUNING    1023        // Les entrées Analog renvoient une valeur entre 0 et 1023
#define MAX_LG_LINE   40          // longueur maximale prévisionelle des lignes du catalogue

class Catalog
{
    public:
        Catalog();
        // initialisations
        void   begin();
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
        // Accès au fichier Catalog.ndx
        void   writeAddStar(long clipPosition);
        void   writeRemoveStar(long clipPosition);
      
    private:
        bool   openCatalogAtPosition(long pos);
        void   closeCatalog();
        String readRandomLine();
        String readNextLine();
        void   parseFields(String medialine);
        String getGenreLabel(int value);
        int    getYearValue(int tuning);
        int    getStarsValue(int value);
        bool   isInRange(int year);
        bool   isNotAsExpected(String mediagenre);
        bool   isAsExpectedRating(String rating);
        // Accès au fichier Catalog.ndx
        void   writeRating(int rating, long clipPosition);
        int    readRating(long clipPosition);

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
        // Le catalogue
        SdFile        FichierIndex;
        unsigned int  RandomMax=10;         
        // Infos sur le dernier Media valide trouvé
        String        LastMedia_ID;   // sert à eviter de tomber deux fois de suite sur le même ID
        String        Media_ID;
        String        Media_Genre;
        String        Media_Year;
        String        Media_Rating;
        // Infos sur les genres apparaissant sur la face avant (White List)
        const String  GenreWhiteList="Classique;Blues;Jazz;Folk;Rock n'Roll;Rock;Chanson;Musiques du monde;";  // Ne pas oublier le ; final
//        byte          GenreWhiteListSize = 8;
        float         GenreLength;
        int           CurrentGenreStart;
        // Infos sur le premier Media ayant la date demandée
        String        FirstMediaID;
        String        FirstMediaYear;
        String        FirstMediaGenre;
        String        FirstMediaRating;
        // Infos temporaires sur la ligne lue dans le catalogue
        String        Field1;       // year
        String        Field2;       // media_id
        String        Field3;       // genre
        String        Field4;       // rating
        // Les curseurs dans la catalogue
        long          FirstcurrentPositionY; // curseur de debut de décade (mode YEAR)
        long          CurrentPositionY;      // curseur pour le mode YEAR
        long          CurrentPositionG;      // curseur pour le mode GENRE
        long          RatingPosition;        // curseur pour le mode RATING

};


#endif // CATALOGCLASS_H_INCLUDED
