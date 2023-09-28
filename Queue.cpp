#include "Queue.h"
#include <stdexcept>

template <typename T>
void Queue<T>::Enqueue(T item) {
   Add(item);
}

template <typename T>
T Queue<T>::Dequeue() {
   if (Count() > 0) {
   T item;
   item = this->Head->Data;
   this->RemoveAt(0);
   return item;
   } else {
      throw std::range_error("La cola no tiene elementos.");
   }
}
