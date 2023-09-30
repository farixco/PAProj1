#include "../include/Queue.h"
#include <iostream>
#include "../include/Song.h"

using std::cout, std::endl;
void QueuePrint(Queue<Song*>* qw) {
      for (int i = 0; i < 3; ++i) {
      cout << qw->GetAt(i)->Name << " | " << qw->GetAt(i)->Artist << " | " << qw->GetAt(i)->Duration << " || ";
      }
      cout << endl;
}

int main() {
   // Nota: Por utilizar Song en ese test, probar que Song pase su propio test primero. Por estar implementada encima de List, probar que List pase su propio test primero.
   Queue<int>* qT = new Queue<int>;
   qT->Enqueue(0);
   qT->Enqueue(1);
   qT->Enqueue(2);
   qT->Enqueue(3);
   int count = qT->Count();
   cout << "T0: Dequeue" << endl;
   for (int i = 0; i < count; ++i) {
      int tmp = qT->Dequeue();
      cout << tmp << " " << endl;
      if (tmp != i) {
	 return 1;
      }
   }
   cout << endl;
   Song* s1 = new Song("Come Together||The Beatles||4:19", "T");
   Song* s2 = new Song("Something||Los Bitols||3:02", "T");
   Song* s3 = new Song("Maxwell's Silver Hammer||Die Beatze||3:27", "T");
   Queue<Song*>* qT2 = new Queue<Song*>;
   qT2->Enqueue(s1);
   qT2->Enqueue(s2);
   qT2->Enqueue(s3);
   cout << "T1: Reorder" << endl;
   cout << "Cola original:" << endl;
   QueuePrint(qT2);
   std::string qualQ1[] = {"Nombre","Artista","Duración"};
   std::string qualQ2[] = {"ascendente","descendente"};
   for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 2; ++j) {
	 cout << "Cola reordenada por " << qualQ1[i] << " " << qualQ2[j] << ":" << endl;
	 qT2->Reorder(i, j);
	 QueuePrint(qT2);
      }
   }
}
