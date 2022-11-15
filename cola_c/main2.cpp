#include <iostream>
#include <math.h>
#include "Nodo.h"
#include "Cola.h"
#include "Pila.h"
using namespace std;

template<class T>
void in_rec(Cola <T>*);

int main(){
  Cola <int>* a = new Cola<int>();
  a->insertar(1);
  a->insertar(2);
  a->insertar(3);
  a->insertar(4);
  a->insertar(5);
  cout << a->ret_p() << endl;
  cout << a->ret_u() << endl;
  in_rec(a);
  cout << a->ret_p() << endl;
  cout << a->ret_u() << endl;
  return 0;
}

template<class T>
void in_rec(Cola <T>*C){
  T tmp = C->ret_p();
  if(C->ret_cp()->ret_sig()){
    C->eliminar();
    in_rec(C);
  }
  C->insertar(tmp);
}

