#include "../include/CD.h"

int CD::IndexOf(Song* cancion) {
   Node* placeholder = Head;
   for (int i = 0; i < Count(); ++i) {
      if (placeholder->Data->Name == cancion->Name &&
	 placeholder->Data->Artist == cancion->Artist &&
	  placeholder->Data->Duration == cancion->Duration) {
	 return i;
      }
      placeholder = placeholder->Next;
   }
   return -1;
}

std::string CD::GetName() {
   return Name;
}

bool CD::Duplicates() {
   for (int i = 0; i < this->Count() - 1; ++i) {
      for (int j = i + 1; j < this->Count(); ++j) {
	 if (this->GetAt(i)->Name == this->GetAt(j)->Name &&
	     this->GetAt(i)->Artist == this->GetAt(j)->Artist &&
	     this->GetAt(i)->Duration == this->GetAt(j)->Duration) {
	    return true;
	 }
      }
   }
   return false;
}
