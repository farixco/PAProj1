#pragma once
#include "Song.h"
#include "List.h"
#include <string>
#include <fstream>
#include <stdexcept>

class CD : public List<Song*> {
   std::string Name;
  public:
   int IndexOf(Song cancion);
   std::string GetName();
   CD(std::string filePath) {
      // código para leer el archivo, más que todo revisión de errores y utilizar Add() para agregarlos a la lista
      std::string line;
      std::ifstream file(filePath);
      if (file.is_open()) {
	 while (std::getline(file, line)) {
	    Song* temp = new Song(line, Name);
	    this->Add(temp);
	    delete temp;
	 }
	 file.close();
      } else {
	 throw std::invalid_argument("Archivo no encontrado o no es de texto.");
      }
   }
};
