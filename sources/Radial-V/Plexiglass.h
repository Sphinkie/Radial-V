/* *******************************************************************************
 *  Face-Avant en Plexiglass
 ********************************************************************************/
#ifndef PLEXIGLASS_H_INCLUDED
#define PLEXIGLASS_H_INCLUDED

#define MAX_TUNING    1023        // Les entrées Analog renvoient une valeur entre 0 et 1023

class Plexiglass
{
  public:
        Plexiglass();
        void setTuning(int tuning);
        String getYear();

  private:
        String getGenreLabel(int tuning);
        int    getYearValue(int tuning);
        int    getStarsValue(int tuning);
        // debuggage
        void   debugGenre();
        void   debugYear();

  public:
        // Valeurs correspondant au Tuning reçu
        String        Genre;                 // Le Genre associé au bouton Tuning
        float         GenreLength;           // Correspond à la 'largeur' du Genre associé au bouton Tuning
        int           Year;                  // L'Année associée au bouton Tuning (ex: 1964)
        int           RangeStart;            // Début de la période associée au bouton Tuning (ex: 1960)
        int           RangeEnd;              // Fin de la période associée au bouton Tuning (ex: 1970)
        int           Rating;                // Le Rating associé au bouton Tunnig

};

#endif // PLEXIGLASS_H_INCLUDED
