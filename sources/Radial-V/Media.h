#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED


class Media
{
  public:
        Media();
        void fillWith(String medialine);
        // Setters
        void setNextMediaPosition(long pos);
        void setSelected(bool select);
        void setRating(int rating);
        // Getters
        int    getYear();
        String getID();
        String getGenre();
        int    getRating();
        long   getNextMediaPosition();
        long   getRatingPosition();
        // Checkers
        bool   isSelected();
        bool   hasGenre(String genre);
        bool   hasYearBetween(int YearStart, int YearEnd);

  private:

        // Infos temporaires sur la ligne lue dans le catalogue
        String        Field1;       // year
        String        Field2;       // media_id
        String        Field3;       // genre
        String        Field4;       // rating
        bool          Selected=false;
        long          NextMediaPosition=0;
        // Infos sur les genres apparaissant sur la face avant (White List)
        const String  GenreWhiteList="Classique;Blues;Jazz;Folk;Rock n'Roll;Rock;Chanson;Musiques du monde;";  // Ne pas oublier le ; final

};

#endif // MEDIA_H_INCLUDED
