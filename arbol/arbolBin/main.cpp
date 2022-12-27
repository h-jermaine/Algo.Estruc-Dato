 #include <iostream>
#include "ArbolBinario.h"
using namespace std;

int main(){

  ArbolBinario<int> * a = new ArbolBinario<int>();
  ArbolBinario<int> * b = new ArbolBinario<int>();

  NodoArbol<int> * ta = new NodoArbol<int>(1);
  NodoArbol<int> * tb = new NodoArbol<int>(2);
  NodoArbol<int> * tc = new NodoArbol<int>(3);

  a->InsertaNodos(ta, 2, tc);
  b->InsertaNodos(tc, 2, ta);

  a->Preorden();
  b->Preorden();

  if(a->SonIguales(a->Raiz, b->Raiz))
    cout << "si son iguales" << endl;
  else
    cout << "no son iguales" << endl;
  return 0;
}
