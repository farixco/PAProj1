#include "../include/CD.h"
#include <iostream>

int main() {
   std::string path = "../ArchivosDePrueba/empty.txt";
   std::cout << "T0: Constructor y Duplicados" << std::endl;
   CD* cede;
   try {
      cede = new CD(path);
      return 1;
   } catch (...) {
      path = "../ArchivosDePrueba/Abbey Road.txt";
      cede = new CD(path);
   }
   std::cout << "T1: Nombre" << std::endl;
   std::cout << cede->GetName() << std::endl;
   if (cede->GetName() != "Abbey Road") {
      return 1;
   }
   std::cout << "T2: Canción" << std::endl;
   Song* canc = new Song("Here Comes the Sun||The Beatles||3:05","Abadía");
   std::cout << "IndexOf: " << cede->IndexOf(canc) << std::endl;
   if (cede->IndexOf(canc) != 6) {
      return 1;
   }
}
