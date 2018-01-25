/* *******************************************************************************
* FAVORITES
*
* Cet objet permet de gérer la liste des clips mp3, indexés selon leur nombre
* d'étoiles (Rating).
******************************************************************************* */

#ifndef FAVORITESCLASS_H_INCLUDED
#define FAVORITESCLASS_H_INCLUDED

class Favorites
{
    public:
        Favorites();
/*        void     addStar(String mediaId);*/
        void     addStar(long pos);
        char     getClipStars(String mediaId);
/*        void     removeStar(String mediaId);*/
        void     removeStar(long clipPosition);

    private:
        
    //variables:
        int    CurrentPosition;
        int    RequestedRating=1;    // Nombre d'étoiles demandé
        int    RandomMax=5;
        String Media_ID;
};

#endif // FAVORITESCLASS_H_INCLUDED
