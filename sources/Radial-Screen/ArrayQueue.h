#ifndef ARRAYQUEUECLASS_H_INCLUDED
#define ARRAYQUEUECLASS_H_INCLUDED

/* *******************************************************************
 Gestion d'une FIFO du type:  [Front x x x x x Rear]
  ---FxxxxR----
**********************************************************************
*/

#define MAX_QUEUE_SIZE 15       // nombre de commandes que l'on veut mémoriser dans la Fifo
#define MAX_DATA_SIZE  50       // doit être dimensionné en fonction du nombre de commandes I2C


class ArrayQueue
{  
  public:
        ArrayQueue();
        void   enQueue(int element, char* texte);
        int    deQueue();
        int    getSize();
        int    getFirst();
        bool   isEmpty();
        String getData(int index);

  private:
        int     Queue[MAX_QUEUE_SIZE];
        int     Front;
        int     Rear;
        String  Data[MAX_DATA_SIZE];
};


#endif // ARRAYQUEUECLASS_H_INCLUDED
