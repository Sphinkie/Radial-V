#ifndef CATALOGFILE_H_INCLUDED
#define CATALOGFILE_H_INCLUDED
#include <SdFat.h>

#define MAX_LG_LINE   40          // longueur maximale prévisionelle des lignes du catalogue

// Accès au fichier Catalog.ndx
class CatalogFile
{
      protected:

        void   begin();
        bool   openCatalogAtPosition(long pos=5);
        bool   openCatalogAtRandomPosition();
        void   closeCatalog();
        long   getCurrentPosition();

        // Lecture/Ecriture de lignes
        String readRandomLine();
        String readNextLine();
              
        // Lecture/Ecriture du Rating
        int    writeAddStar(long clipPosition);
        int    writeRemoveStar(long clipPosition);
        int    readRating(long clipPosition);
        void   writeRating(int rating, long clipPosition);

        unsigned int  RandomMax=10;         

      private:
        SdFile        FichierIndex;

};

#endif // CATALOGFILE_H_INCLUDED
