#pragma once
#include "Song.h"
#include "List.h"
#include <string>
#include <fstream>
#include <stdexcept>
#include <filesystem>
    
class CD : public List<Song*> {
   std::string Name;
   bool Duplicates();
  public:
   int IndexOf(Song* cancion);
   std::string GetName();
   CD(std::string filePath) {
      std::string line;
      std::ifstream file(filePath);
      if (file.is_open()) {
	 std::filesystem::path p(filePath);
	 Name = p.stem();
	 while (std::getline(file, line)) {
	    Song* temp = new Song(line, Name);
	    this->Add(temp);
	    delete temp;
	 }
	 file.close();
      } else {
	 throw std::invalid_argument("Archivo no encontrado o no es de texto.");
      }
      if (Duplicates()) {
	 delete this;
	 throw std::invalid_argument("Archivo contiene líneas duplicadas.");
      }
   }
};
