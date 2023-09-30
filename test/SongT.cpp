#include "../include/Song.h"
#include <iostream>
using std::cout, std::endl;

int main() {
   std::string rawData = "Maxwell's Silver Hammer||The Beatles||3:27";
   std::string rawData2 = "Sun King||The Beatles||2:26";
   cout << "T0: Song constructor" << endl;
   Song* c1 = new Song(rawData, "Abbey Road");
   if (c1->Name != "Maxwell's Silver Hammer" || c1->Artist != "The Beatles" || c1->Duration != "3:27") {
      return 1;
   }
   c1 = new Song(rawData2, "Abbey Road");
   if (c1->Name != "Sun King" || c1->Artist != "The Beatles" || c1->Duration != "2:26") {
      return 1;
   }
   try {
      c1 = new Song("s|dfsgdfg|fgfdg||fdssdf||ss", "|||");
      return 1;
   } catch (std::invalid_argument e) {
      return 0;
   }
}
