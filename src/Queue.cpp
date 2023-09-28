#include "../include/Queue.h"
#include <stdexcept>
#include "../include/Song.h"
#include <algorithm>

template <typename T>
void Queue<T>::Enqueue(T item) {
   this->Add(item);
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
void Queue<Song*>::Reorder(int type, int order) {
   //  0: artista, 1: canción, 2: duración || 0 descendiente, 1 ascendiente
   int count = Count();
   List<Song*>* listTmp = new List;
   for (int i = 0; i < count; ++i) {
      listTmp->Add(Dequeue());
   }
   if (type == 0) {
      // utilizando std::sort, función anónima para poder compararlos
      if (order == 0) {
	 std::sort(0, listTmp->Count(), [](const Song* lhs, const Song* rhs) {
	    return lhs->Artist > rhs->Artist;
	 });
      } else if (order == 1) {
	 std::sort(0, listTmp->Count(), [](const Song* lhs, const Song* rhs) {
	    return lhs->Artist < rhs->Artist;
	 });
      } else {
	 throw std::invalid_argument("Orden de ordenamiento inválido.");
      }
   } else if (type == 1) {
      // utilizando std::sort, función anónima para poder compararlos
      if (order == 0) {
	 std::sort(0, listTmp->Count(), [](const Song* lhs, const Song* rhs) {
	    return lhs->Name > rhs->Name;
	 });
      } else if (order == 1) {
	 std::sort(0, listTmp->Count(), [](const Song* lhs, const Song* rhs) {
	    return lhs->Name < rhs->Name;
	 });
      } else {
	 throw std::invalid_argument("Orden de ordenamiento inválido.");
      }
   } else if (type == 2) {
      // utilizando std::sort, función anónima para poder compararlos
      if (order == 0) {
	 std::sort(0, listTmp->Count(), [](const Song* lhs, const Song* rhs) {
	    return lhs->Duration > rhs->Duration;
	 });
      } else if (order == 1) {
	 std::sort(0, listTmp->Count(), [](const Song* lhs, const Song* rhs) {
	    return lhs->Duration < rhs->Duration;
	 });
      } else {
	 throw std::invalid_argument("Orden de ordenamiento inválido.");
      }
   } else {
      throw std::invalid_argument("Tipo de reordenamiento inválido.");
   }
   for (int i = 0; i < count; ++i) {
      Enqueue(listTmp->GetAt(i));
   }
   delete listTmp;
}
