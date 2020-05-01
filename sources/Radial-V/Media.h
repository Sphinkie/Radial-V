#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED


class Media
{
  public:
        Media();
        void fillWith(String medialine);
        // Setters
        void setSelected(bool select);
        // Getters
        String getYear();
        String getID();
        String getGenre();
        String getRating();
        // Checkers
        bool   isSelected();
        bool   isGenre(String genre);
        bool   hasYearBetween(int YearStart, int YearEnd);

  private:

        // Infos temporaires sur la ligne lue dans le catalogue
        String        Field1;       // year
        String        Field2;       // media_id
        String        Field3;       // genre
        String        Field4;       // rating
        bool          Selected=false;
};

#endif // MEDIA_H_INCLUDED
