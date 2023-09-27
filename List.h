#pragma once
template <typename T>
class List {
   struct Node {
      Node* Next = nullptr;
      T Data;
   };
  protected:
   Node* Head = nullptr;
   Node* Tail = nullptr;
   int Length = 0;
  public:
   void Add(T item);
   void RemoveAt(int index);
   T GetAt (int index);
   void SetAt(int index, T item);
   int IndexOf(T item);
   int Count();
};
