#include <iostream>
#include "ArbolBinario.h"
using namespace std;

int main(){
  ArbolBinario<int> *ab = new ArbolBinario<int>();
  ab->InsertarArbol(304);
  ab->InsertarArbol(550);
  ab->InsertarArbol(143);
  ab->InsertarArbol(2020);
  //cout << ab->m() << endl;
  ab->Preorden();
  return 0;
}
