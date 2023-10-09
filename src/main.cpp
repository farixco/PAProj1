#include <iostream>
#include <filesystem>
#include "../include/CD.h"
#include "../include/List.h"
#include "../include/Queue.h"

using std::cout, std::cin, std::stoi, std::endl, std::string, std::getline, std::filesystem::directory_iterator, std::filesystem::exists;

int main(int argc, char *argv[]) {
   while (1) {
      string path = "";
      while (!exists(path)) {
	 cout << "Ingrese dirección válida de directorio. Para salir, presione Ctrl-C." << endl;
	 getline(cin, path);
      }
      string archivo = "";
      List<CD*>* listaCD = new List<CD*>;
      for (const auto & file: directory_iterator(path)) {
	 archivo = file.path().string();
	 try {
	    CD* tmp = new CD(archivo);
	    listaCD->Add(tmp);
	 } catch (std::exception& exc) {
	    cout << "El archivo: " << archivo << " contiene errores, y no ha podido ser leído. Por favor corregir el error." << endl;
	    std::cerr << exc.what() << endl;
	    std::exit(1);
	 }
      }
      Queue<Song*>* colaRepro = new Queue<Song*>;
      string op;
      int opI;
      while (1) {
	 cout << "Ingrese número de opción." << endl;
	 cout << "0. Cargar Respaldos" << endl;
	 cout << "1. Agregar Canción" << endl;
	 cout << "2. Ver Cola de Reproducción" << endl;
	 cout << "3. Reproducción Actual" << endl;
	 cout << "4. Reproducir Siguiente" << endl;
	 cout << "5. Ordenar" << endl;
	 cout << "6. Salir" << endl;
	 std::getline(cin, op);
	 try {
	    opI = stoi(op);
	 } catch (...) {
	    opI = -1;
	 }
	 switch (opI) {
	    case 0: break;
	    case 1: {int oIt, oIt2;
	       cout << "Elija un CD de la siguiente lista:" << endl;
	       for (int i = 0; i < listaCD->Count(); ++i) {
		  cout << "Índice: " << i << " Nombre: " << listaCD->GetAt(i)->GetName() << endl;
	       }
	       getline(cin, op);
	       try {
		  oIt = stoi(op);
	       } catch (...) {
		  oIt = -1;
	       }
	       if (oIt >= 0 && oIt < listaCD->Count()) {
		  cout << "Elija una canción de la siguiente lista:" << endl;
		  for (int i = 0; i < listaCD->GetAt(oIt)->Count(); ++i) {
		     cout << "Índice: " << i << " Nombre: " << listaCD->GetAt(oIt)->GetAt(i)->Name << endl;
		  }
		  getline(cin, op);
		  try {
		     oIt2 = stoi(op);
		  } catch (...) {
		     oIt2 = -1;
		  }
		  if (oIt2 >= 0 && oIt2 < listaCD->GetAt(oIt)->Count()) {
		     colaRepro->Enqueue(listaCD->GetAt(oIt)->GetAt(oIt2));
		  } else {
		     cout << "Índice inválido." << endl;
		  }
	       } else {
		  cout << "Índice inválido." << endl;
	       }
	       continue; }
	    case 2: { cout << "Indique 0 si desea ver la cola de reproducción actual. Indique 1 si la quiere ver ordenada por nombre de la canción, 2 por nombre del artista y 3 por duración." << endl;
	       getline(cin, op);
	       int oT;
	       try {
		  oT = stoi(op);
	       } catch (...) {
		  oT = -1;
	       }
	       Queue<Song*>* qT = new Queue<Song*>;
	       switch (oT) {
		  case 0: for (int i = 0; i < colaRepro->Count(); ++i) {
		     cout << "Nombre: " << colaRepro->GetAt(i)->Name << " Artista: " << colaRepro->GetAt(i)->Artist << " Duración: " << colaRepro->GetAt(i)->Duration << " Álbum: " << colaRepro->GetAt(i)->Album << endl;
		  }
		     continue;
		  case 1: for (int i = 0; i < colaRepro->Count(); ++i) {
			qT->Enqueue(colaRepro->GetAt(i));
		     }
		     qT->Reorder(0, 0);
		     for (int i = 0; i < qT->Count(); ++i) {
			cout << "Nombre: " << qT->GetAt(i)->Name << " Artista: " << qT->GetAt(i)->Artist << " Duración: " << qT->GetAt(i)->Duration << " Álbum: " << qT->GetAt(i)->Album << endl;
		     }
		     continue;
		  case 2: for (int i = 0; i < colaRepro->Count(); ++i) {
			qT->Enqueue(colaRepro->GetAt(i));
		     }
		     qT->Reorder(1, 0);
		     for (int i = 0; i < qT->Count(); ++i) {
			cout << "Nombre: " << qT->GetAt(i)->Name << " Artista: " << qT->GetAt(i)->Artist << " Duración: " << qT->GetAt(i)->Duration << " Álbum: " << qT->GetAt(i)->Album << endl;
		     }
		     continue;
		  case 3: for (int i = 0; i < colaRepro->Count(); ++i) {
			qT->Enqueue(colaRepro->GetAt(i));
		     }
		     qT->Reorder(2, 0);
		     for (int i = 0; i < qT->Count(); ++i) {
			cout << "Nombre: " << qT->GetAt(i)->Name << " Artista: " << qT->GetAt(i)->Artist << " Duración: " << qT->GetAt(i)->Duration << " Álbum: " << qT->GetAt(i)->Album << endl;
		     }
		     continue;
		  default: cout << "Opción inválida." << endl;
		     continue;
	       }
	       continue; }
	    case 3: { cout << "Actualmente reproduciendo: " << "Nombre: " << colaRepro->GetAt(0)->Name << " Artista: " << colaRepro->GetAt(0)->Artist << " Duración: " << colaRepro->GetAt(0)->Duration << " Álbum: " << colaRepro->GetAt(0)->Album << endl;
	       continue; }
	    case 4: { colaRepro->Enqueue(colaRepro->Dequeue());
	       cout << "Actualmente reproduciendo: " << "Nombre: " << colaRepro->GetAt(0)->Name << " Artista: " << colaRepro->GetAt(0)->Artist << " Duración: " << colaRepro->GetAt(0)->Duration << " Álbum: " << colaRepro->GetAt(0)->Album << endl;
	       continue; }
	    case 5: { cout << "Indique 0 si desea ordenar la cola por nombre, 1 por artista y 2 por duración." << endl;
	       int oT, oT2;
	       getline(cin, op);
	       try {
		  oT = stoi(op);
	       } catch (...) {
		  oT = -1;
	       }
	       if (oT == 0 || oT == 2 || oT == 3) {
		  cout << "Indique 0 si desea la cola ordenada en tipo ascendente y 1 en tipo descendente." << endl;
		  getline(cin, op);
		  try {
		     oT2 = stoi(op);
		  } catch (...) {
		     oT2 = -1;
		  }
		  if (oT2 == 0 || oT2 == 1) {
		     colaRepro->Reorder(oT, oT2);
		  } else {
		     cout << "Opción inválida." << endl;
		  }
	       } else {
		  cout << "Opción inválida." << endl;
	       }
	       continue; }
	    case 6: std::exit(0);
	    default: cout << "Opción inválida." << endl;
	       continue;
	 }
	 break;
      }
   }
}
