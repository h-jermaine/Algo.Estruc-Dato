#include <iostream>
#include <math.h>
#include "Nodo.h"
#include "Cola.h"
#include "Pila.h"
using namespace std;

template<class T>
Cola <T>* invertir(Cola <T>* C);

int main(){
  Cola <int>* a = new Cola<int>();
  a->insertar(1);
  a->insertar(2);
  a->insertar(3);
  a->insertar(4);
  a = invertir(a);
  return 0;
}

template<class T>
Cola <T>*invertir(Cola <T>* C){
  Pila <T>* aux = new Pila<T>;
  while(C->ret_cp() != nullptr){
    aux->insertar(C->ret_p());
    C->eliminar();
  }
  while(aux->ret_u()){
    C->insertar(aux->sima());
    aux->eliminar();
  }
  return C;
}
