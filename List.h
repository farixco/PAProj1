#pragma once
template <typename T>
class List {
  protected:
   struct Node {
      Node* next = nullptr;
      T data;
   };
  public:
   void Add(T item);
   void RemoveAt(int index);
   T GetAt (int index);
   void SetAt(int index, T item);
   int IndexOf(T item);
};
