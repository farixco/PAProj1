#include "List.h"

template <typename T>
void List<T>::Add(T item) {
   if (Head == nullptr) {
      Head = new Node*;
      Head->Data = item;
      Tail = Head;
   } else {
      Node* Placeholder = new Node*;
      Placeholder->Data = item;
      Placeholder->Next = nullptr;
      Tail->Next = Placeholder;
      Tail = Placeholder;
   }
}

template <typename T>
void List<T>::RemoveAt(int index) {
   Node* placeholder = Head;
   for (int i = 0; i < index; ++i) {
      placeholder = placeholder->Next;
   }
   Node* p2 = placeholder->Next->Next;
   delete placeholder->Next;
   placeholder->Next = p2;
}
