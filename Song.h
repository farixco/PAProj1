#pragma once
#include <string>
#include <stdexcept>

class Song {
  public:
   std::string Name;
   std::string Artist;
   std::string Duration;
   std::string Album;
   Song(std::string rawData, std::string _album) {
      if (rawData.find("||") == std::string::npos || rawData[0] == '|' || rawData[rawData.length() - 1] == '|') {
	 throw std::invalid_argument("Declaración de canción inválida. (1)");
      } else {
	 Album = _album;
	 int timesFound = 0;
	 int lastFound;
	 for (int i = 0; i < rawData.length(); ++i) {
	    if (rawData.substr(i, 2) == "||") {
	       switch (timesFound) {
		  case 0: Name = rawData.substr(0, i - 1);
		     ++timesFound;
		     lastFound = i + 2;
		     break;
		  case 1: Artist = rawData.substr(lastFound, i - lastFound);
		     ++timesFound;
		     lastFound = i + 2;
		     break;
		  case 2: Duration = rawData.substr(lastFound);
		     ++timesFound;
		     break;
		  default: throw std::invalid_argument("Declaración de canción inválida. (2)");
		     break;
	       }
	    }
	 }
      }
   }
};
