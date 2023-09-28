#pragma once
#include "List.h"

template <typename T>
class Queue : private List<T> {
   // construída sobre la lista, pero solo permite acceso de ciertas maneras;
  public:
   using List<T>::Count;
   using List<T>::GetAt;
   using List<T>::IndexOf;
   void Enqueue(T item);
   T Dequeue();
   // el método para reordenar recibe un int por el tipo de reordenamiento que hace. 0 es por artista, 1 es por canción y 2 es por duración. el int order recibe 0 para descendiente y 1 para ascendente.
   void Reorder(int type, int order);
};
