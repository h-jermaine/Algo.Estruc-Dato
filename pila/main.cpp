#include <iostream>
#include "Nodo.h"
#include <string>
#include "Pila.h"
using namespace std;

int main(){
  Pila *p = new Pila();
  p->insertar(1);
  p->insertar(2);
  p->insertar(3);
  cout << p->sima() << endl;
  p->eliminar();
  cout << p->sima() << endl;


  return 0;
}
