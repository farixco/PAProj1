#include "../include/Queue.h"
#include <stdexcept>
#include "../include/Song.h"
#include <functional>
// método especializado solo para ordenar canciones
template <>
void Queue<Song*>::Reorder(int type, int order) {   //  0: nombre canción, 1: artista, 2: duración || 0 descendiente, 1 ascendiente
   int count = Count();
   List<Song*>* listTmp = new List;
   for (int i = 0; i < count; ++i) {
      listTmp->Add(Dequeue());
   }
   if (type == 0) {
      if (order == 0) {
	 for (int i = 0; i < count; ++i) {
	    for (int j = 0; j < count; ++j) {
	       if (listTmp->GetAt(i)->Name < listTmp->GetAt(j)->Name) {
		  Song* tmp = listTmp->GetAt(i);
		  listTmp->SetAt(i, listTmp->GetAt(j));
		  listTmp->SetAt(j, tmp);
	       }
	    }
	 }
      } else if (order == 1) {
	 for (int i = 0; i < count; ++i) {
	    for (int j = 0; j < count; ++j) {
	       if (listTmp->GetAt(i)->Name > listTmp->GetAt(j)->Name) {
		  Song* tmp = listTmp->GetAt(i);
		  listTmp->SetAt(i, listTmp->GetAt(j));
		  listTmp->SetAt(j, tmp);
	       }
	    }
	 }
      } else {
	 throw std::invalid_argument("Orden de ordenamiento inválido.");
      }
   } else if (type == 1) {
      if (order == 0) {
	 for (int i = 0; i < count; ++i) {
	    for (int j = 0; j < count; ++j) {
	       if (listTmp->GetAt(i)->Artist < listTmp->GetAt(j)->Artist) {
		  Song* tmp = listTmp->GetAt(i);
		  listTmp->SetAt(i, listTmp->GetAt(j));
		  listTmp->SetAt(j, tmp);
	       }
	    }
	 }
      } else if (order == 1) {
	 for (int i = 0; i < count; ++i) {
	    for (int j = 0; j < count; ++j) {
	       if (listTmp->GetAt(i)->Artist > listTmp->GetAt(j)->Artist) {
		  Song* tmp = listTmp->GetAt(i);
		  listTmp->SetAt(i, listTmp->GetAt(j));
		  listTmp->SetAt(j, tmp);
	       }
	    }
	 }
      } else {
	 throw std::invalid_argument("Orden de ordenamiento inválido.");
      }
   } else if (type == 2) {
      if (order == 0) {
	 for (int i = 0; i < count; ++i) {
	    for (int j = 0; j < count; ++j) {
	       if (listTmp->GetAt(i)->Duration < listTmp->GetAt(j)->Duration) {
		  Song* tmp = listTmp->GetAt(i);
		  listTmp->SetAt(i, listTmp->GetAt(j));
		  listTmp->SetAt(j, tmp);
	       }
	    }
	 }
      } else if (order == 1) {
	 for (int i = 0; i < count; ++i) {
	    for (int j = 0; j < count; ++j) {
	       if (listTmp->GetAt(i)->Duration > listTmp->GetAt(j)->Duration) {
		  Song* tmp = listTmp->GetAt(i);
		  listTmp->SetAt(i, listTmp->GetAt(j));
		  listTmp->SetAt(j, tmp);
	       }
	    }
	 }
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
