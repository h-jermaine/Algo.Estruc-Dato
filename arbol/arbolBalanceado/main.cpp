#include <iostream>
#include "ArbolBalanceado.h"
using namespace std;

int main(){
  ArbolBalanceado<int> * a1 = new ArbolBalanceado<int>();
  NodoArbolBal<int> * Apunt1;
  a1->InsertaBalanceado(11);
  a1->InsertaBalanceado(22);
  a1->InsertaBalanceado(1);
  a1->Imprime();

  return 0;
}
