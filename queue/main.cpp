#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "Hnode.h"
#include "Hqueue.h"
using namespace std;
class Tiro_plato{
  public:
    string apellido;
    string nombre;
    int numero_dorsal;
    int platos_rotos;
    Tiro_plato():apellido(""), nombre(""), numero_dorsal(0), platos_rotos(0){}
    Tiro_plato(string a, string n, int d, int r):apellido(a), nombre(n), numero_dorsal(d), platos_rotos(r){}
};

int main(){
  Hqueue<Tiro_plato> * a = new Hqueue<Tiro_plato>();
  Hqueue<Tiro_plato> * b = new Hqueue<Tiro_plato>();
  Tiro_plato x[3];
  string archivo = "input.txt";
  ifstream f(archivo.c_str());
  string line;
  string apell, nom;
  int num_dor;
  int num_ro;
  while(getline(f, line)){
    stringstream s(line);
    while(s >> apell >> nom >> num_dor >> num_ro){
      Tiro_plato t(apell, nom, num_dor, num_ro);
      a->Insertar(t);
      if(num_ro > x[0].platos_rotos)
	x[0] = t;
      if((num_ro > x[1].platos_rotos) && (x[0].platos_rotos != num_ro))
	x[1] = t;
      if((num_ro > x[2].platos_rotos) && (num_ro != x[1].platos_rotos) && (num_ro != x[0].platos_rotos))
	x[2] = t;
    }
  }
  for(int i = 0; i < 3; i++)
    b->Insertar(x[i]);
  while(a->RetornaPrimero()){
    if((a->RetornaDato().platos_rotos != x[0].platos_rotos) && (a->RetornaDato().platos_rotos != x[1].platos_rotos) && (a->RetornaDato().platos_rotos != x[2].platos_rotos))
      b->Insertar(a->RetornaDato());
    a->Eliminar();
  }
  while(b->RetornaPrimero()){
    cout << b->RetornaDato().apellido << " " << b->RetornaDato().nombre << " " << b->RetornaDato().numero_dorsal << " " << b->RetornaDato().platos_rotos << endl;
    b->Eliminar();
  }
  return 0;
}

