#include "../include/List.h"
#include <stdexcept>

template <typename T>
void List<T>::Add(T item) {
   if (Head == nullptr) {
      Head = new Node*;
      Head->Data = item;
      Tail = Head;
      ++Length;
   } else {
      Node* Placeholder = new Node*;
      Placeholder->Data = item;
      Placeholder->Next = nullptr;
      Tail->Next = Placeholder;
      Tail = Placeholder;
      ++Length;
   }
}

template <typename T>
void List<T>::RemoveAt(int index) {
   if (index < Length && index >= 0) {
      if (index > 0) {
	 Node* placeholder = Head;
	 for (int i = 0; i < index - 1; ++i) {
	    placeholder = placeholder->Next;
	 }
	 Node* p2 = placeholder->Next->Next;
	 delete placeholder->Next;
	 placeholder->Next = p2;
      } else {
	 Head = Head->Next;
      }
      --Length;
   } else {
      throw std::out_of_range("Índice no existe.");
   }
}

template <typename T>
T List<T>::GetAt(int index) {
   if (index < Length && index >= 0) {
      Node* placeholder = Head;
      for (int i = 0; i <= index; ++i) {
	 placeholder = placeholder->Next;
      }
      return placeholder->Data;
   } else {
      throw std::out_of_range("Índice no existe.");
   }
}

template <typename T>
void List<T>::SetAt(int index, T item) {
   if (index < Length && index >= 0) {
      Node* placeholder = Head;
      for (int i = 0; i <= index; ++i) {
	 placeholder = placeholder->Next;
      }
      placeholder->Data = item;
   } else {
      throw std::out_of_range("Índice no existe.");
   }
}

template <typename T>
int List<T>::IndexOf(T item) {
   Node* placeholder = Head;
   int reps = 0;
   while (placeholder->Data != item || placeholder->Next != nullptr) {
      placeholder = placeholder->Next;
      ++reps;
   }
   if (placeholder->Data == item) {
      return reps;
   } else {
      return -1;
   }
}

template <typename T>
int List<T>::Count() {
   return Length;
}
