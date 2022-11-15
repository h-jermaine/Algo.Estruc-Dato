#include <iostream>
#include "ArbolBalanceado.h"
using namespace std;

int main(){
  ArbolBalanceado<int> * a1 = new ArbolBalanceado<int>();
  NodoArbolBal<int> * Apunt1;
  int Band;
  Apunt1 = a1->RegresaRaiz();
  a1->InsertaBalanceado(11, Apunt1, &Band);
  Apunt1 = a1->RegresaRaiz();
  a1->Imprime(Apunt1);

  return 0;
}
