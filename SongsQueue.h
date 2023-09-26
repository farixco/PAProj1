#pragma once
#include "Queue.h"
#include "Song.h"
#include "List.h"

class SongsQueue : public Queue<Song> {
  public:
   // el método para reordenar recibe un int por el tipo de reordenamiento que hace. 0 es por artista, 1 es por canción y 2 es por duración
   void Reorder(int type);
};
