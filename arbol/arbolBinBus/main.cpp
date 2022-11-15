#include <iostream>
#include "ArbolBinBusqueda.h"
using namespace std;

int main(){
  ArbolBinBus<int> * ab = new ArbolBinBus<int>();
  ab->InsertaNodoSinRep(3);
  ab->Busqueda(3);
  cout << ab->m() << endl;
  return 0;
}
