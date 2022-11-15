#include <iostream>
#include "ListaDobLiga.h"
using namespace std;

template<class T>
ListaDobLiga<T> * NuevaL(ListaDobLiga<T> *, ListaDobLiga<T> *);

int main(){
  ListaDobLiga<int> * LA = new ListaDobLiga<int>();
  ListaDobLiga<int> * LB = new ListaDobLiga<int>();
  ListaDobLiga<int> * L = new ListaDobLiga<int>();
  LA->InsertaFinal(1);
  LA->InsertaFinal(3);
  LA->InsertaFinal(5);
  LA->InsertaFinal(0);
  LB->InsertaFinal(1);
  LB->InsertaFinal(2);
  LB->InsertaFinal(3);
  LB->InsertaFinal(4);
  L = NuevaL(LA, LB);
  L->m();
  return 0;
}

template<class T>
ListaDobLiga<T> * NuevaL(ListaDobLiga<T> * La, ListaDobLiga<T> * Lb){
  ListaDobLiga<T> * aux = new ListaDobLiga<T>();
  NodoDobleLiga<T> * aux2 = La->RetornaPrimero();
  while(aux2){
    NodoDobleLiga<T> * tmp = Lb->RetornaPrimero();
    while(tmp){
      aux->InsertaFinal(aux2->Info * tmp->Info);
      tmp = tmp->LigaDer;
    }
    aux2 = aux2->LigaDer;
  }
  return aux;
}
