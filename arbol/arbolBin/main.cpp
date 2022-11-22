 #include <iostream>
#include "ArbolBinario.h"
using namespace std;

int main(){
  ArbolBinario<int> * ab = new ArbolBinario<int>();
  ArbolBinario<int> * ac = new ArbolBinario<int>();
  ab->InsertarArbol(5);
  ab->InsertarArbol(6);
  ab->InsertarArbol(3);
  ab->InsertarArbol(4);
  //ab->InsertarArbol(2);

  ac->InsertarArbol(2);
  ac->InsertarArbol(3);
  ac->InsertarArbol(1);
  //cout << ab->m() << endl;
  //ab->Preorden();
  //ac->Preorden();
  if(ab->SonIguales(ab->Raiz, ac->Raiz))
    cout << "si son" << endl;
  else
    cout << "no son" << endl;
  if(ab->completo(ab->Raiz))
    cout << "cheroka" << endl;
  else
    cout << "no cheroka " << endl;
  return 0;
}
