#pragma once
#include "Song.h"
#include "List.h"
#include <string>

class CD : public List<Song> {
  public:
   int IndexOf(Song cancion);
   CD(std::string directoryPath) {
      // código para leer el archivo, más que todo revisión de errores y utilizar Add() para agregarlos a la lista
   }
};
