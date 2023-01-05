#include <iostream>
#include "Cola.h"
#include "Nodo.h"
using namespace std;
Cola *cambiar_posiciones(Cola * c){
  Cola *aux = new Cola();
  while(c->ret_primero()){
    aux->insertar(c->ret_primero()->ret_dato());
    c->eliminar();
  }
  return aux;
}
int main(){
  Cola *c = new Cola();
  Cola *b = new Cola();
  c->insertar(1);
  c->insertar(3);
  c->insertar(5);
  b = cambiar_posiciones(c);
  b->mostrar();
  return 0;
}
