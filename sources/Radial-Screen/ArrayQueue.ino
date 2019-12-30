#include "ArrayQueue.h"

/* *******************************************************************
 Gestion d'une FIFO du type:  [Front x x x x x Rear]
  ---FxxxxR----
**********************************************************************
*/

// -------------------------------------------------------------------
// Constructeur
// -------------------------------------------------------------------
ArrayQueue::ArrayQueue()
{
  Front = 0;
  Rear  = 0;
}      
 
// -------------------------------------------------------------------
// On met un element dans la FIFO (par le Rear). Exemples:
// xR---------
// --FxxxxR---
// xR----Fxxxx  
// Quand la file est pleine, les nouveaux éléments sont ignorés! 
//  xxFwwwRxxxxx
// -------------------------------------------------------------------
void ArrayQueue::enQueue(int element, char* texte)
{
  if (this->getSize() == MAX_QUEUE_SIZE-1) 
  {
    Serial.println(F("Warning: overwriting ArrayQueue"));
    Serial.println("  Cannot enQueue. Front=" + String(Front) + " Rear="+String(Rear));
    return;
  }
  // On stocke les données founies
  Queue[Rear] = element;
  Data[element] = texte;
  // Modulo is used so that rear indicator can wrap around
  Rear = ++Rear % MAX_QUEUE_SIZE;
  // Serial.println("  Item enQueued. Front=" + String(Front) + " Rear="+String(Rear));
}      

// -------------------------------------------------------------------
// On retire un élément de la liste. Renvoie -1 si la liste est vide.
// -------------------------------------------------------------------
int ArrayQueue::deQueue()
{          
  if (this->isEmpty()) return -1;

  int Value = Queue[Front];

  // Modulo is used so that front indicator can wrap around
  Front = ++Front % MAX_QUEUE_SIZE;
  // Serial.println("  Item deQueued. Front=" + String(Front) + " Rear="+String(Rear));

  return Value;   
}      
 
// -------------------------------------------------------------------
// Renvoie le dernier element de la FIFO, mais sans le dépiler.
// Renvoie -1 si la liste est vide.
// -------------------------------------------------------------------
int ArrayQueue::getFirst()
{          
  if (this->isEmpty()) return -1;
  return Queue[Front];
}
 
// -------------------------------------------------------------------
// Renvoie le nombre d'items dans la liste. Exemples:
// FR---------  : Size : 1-0 = 1 -> 1 item
// --FxxxxR---  : Size : 7-2 = 5 -> 5 items
// xR----Fxxxx  : Size : 11-6+1 = 6 -> 6 items
// R---------F  : Size : 11-10+0= 1 -> 1 item
// -------------------------------------------------------------------
int ArrayQueue::getSize()
{
  if (Front <= Rear)
    return (Rear - Front);
  else
    return (MAX_DATA_SIZE-Front+Rear);
}
 
// -------------------------------------------------------------------
// Renvoie TRUE si la FIFO est vide. (cad si R=F).
// -------------------------------------------------------------------
bool ArrayQueue::isEmpty()
{
  return (Front == Rear) ? true : false;
}

// -------------------------------------------------------------------
// Renvoie les Data situés à un index donné de la FIFO
// -------------------------------------------------------------------
String ArrayQueue::getData(int index)
{          
  return Data[index];
}
 
