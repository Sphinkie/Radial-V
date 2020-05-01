#ifndef PLEXIGLASS_H_INCLUDED
#define PLEXIGLASS_H_INCLUDED

#define MAX_TUNING    1023        // Les entrées Analog renvoient une valeur entre 0 et 1023

class Plexiglass
{
  public:
        Plexiglass();
        void setTuning(int tuning);

  private:
        String getGenreLabel(int tuning);
        int    getYearValue(int tuning);
        int    getStarsValue(int tuning);
        // debugage
        void   debugGenre();
        void   debugYear();

  public:
        // Valeurs correspondant au dernier Tuning reçu
        float         GenreLength;
        int           CurrentGenreStart;
        int           RangeStart;            // Année demandée: Début de la période (ex: 1960)
        int           RangeEnd;              // Année demandée: Fin de la période (ex: 1970)
        String        Genre;                 // Le Genre associé au bouton Tuning
        int           Rating;                // Le Rating associé au bouton Tunnig
        int           Year;                  // L'Année associée au bouton Tuning (ex: 1964)

};

#endif // PLEXIGLASS_H_INCLUDED
