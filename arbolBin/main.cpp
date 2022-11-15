#include <iostream>
#include "ArbolBinario.h"
using namespace std;

int main(){
  ArbolBinario<int> *ab = new ArbolBinario<int>();
  ab->InsertarArbol(2);
  ab->InsertarArbol(3);
  cout << ab->m() << endl;
  return 0;
}
