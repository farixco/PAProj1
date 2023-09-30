#pragma once
#include "List.h"
#include <stdexcept>

template <typename T>
class Queue : private List<T> {
   // construída sobre la lista, pero solo permite acceso de ciertas maneras; por usar templates, implementación en el header
  public:
   using List<T>::Count;
   using List<T>::GetAt;
   using List<T>::IndexOf;
   void Enqueue(T item) {
      this->Add(item);
   }
   T Dequeue() {
      if (Count() > 0) {
	 T item;
	 item = this->Head->Data;
	 this->RemoveAt(0);
	 return item;
      } else {
	 throw std::range_error("La cola no tiene elementos.");
      }
   }
   // El primer argumento del método indica cual tipo de ordenamiendo se realizará. 0 es por Nombre, 1 por Artista y 2 por Duración. El segundo argumento indica el orden. 0 es Ascendente y 1 es Descendente. SOLO DISPONIBLE CUANDO ESTÁ INSTANCIADO COMO QUEUE<SONG*>
   void Reorder(int type, int order);
};
