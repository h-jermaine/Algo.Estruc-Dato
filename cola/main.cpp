#include <iostream>
#include "Cola.h"
#include "Nodo.h"
using namespace std;

int main(){
  Cola *c = new Cola();
  Cola *b = new Cola();
  c->asignar(1);
  c->asignar(3);
  c->asignar(5);
  b->asignar(2);
  b->asignar(4);
  b->asignar(6);
  c = c->mezclar(b);

  c->mostrar_cola();
  return 0;
}
