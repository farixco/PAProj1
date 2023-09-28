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
};
