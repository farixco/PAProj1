#include "Queue.h"
#include <stdexcept>
#include "Song.h"

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

// método especializado solo para ordenar canciones
template <>
void Queue<Song*>::Reorder(int type) {
   if (type == 0) {
      // implementar más tarde
   } else if (type == 1) {
      // implementar más tarde
   } else if (type == 2) {
      // implementar más tarde
   } else {
      throw std::invalid_argument("Tipo de reordenamiento inválido.");
   }
}
