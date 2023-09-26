#pragma once
#include "List.h"

template <typename T>
class Queue : private List<T> {
   // construída sobre la lista, pero solo permite acceso de ciertas maneras;
  public:
   void Enqueue(T item);
   T Dequeue();
};
