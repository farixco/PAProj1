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
