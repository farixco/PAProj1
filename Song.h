#pragma once
#include <string>

class Song {
  protected:
   std::string Name;
   std::string Artist;
   std::string Duration;
   std::string Album;
  public:
   Song(std::string rawData) {
      // implementar código para leer una línea
   }
};
