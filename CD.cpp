#include "CD.h"

int CD::IndexOf(Song* cancion) {
   Node* placeholder = Head;
   int index = 0;
   while (placeholder->Data->Name != cancion->Name &&
	  placeholder->Data->Artist != cancion->Artist &&
	  placeholder->Data->Duration != cancion->Duration &&
	  placeholder != Tail) {
      placeholder = placeholder->Next;
      ++index;
   }
   if (placeholder == Tail && (placeholder->Data->Name != cancion ->Name && placeholder->Data->Artist != cancion->Artist && placeholder->Data->Duration != cancion->Duration)) {
      return -1;
   } else {
      return index;
   }
}

std::string CD::GetName() {
   return Name;
}
