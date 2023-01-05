#include <iostream>
#include "Nodo.h"
#include "Lista.h"
using namespace std;

template<class T>
Lista<T> * Mesclar(Lista<T> *, Lista<T> *);

int main(){
  Lista<int> * a = new Lista<int>();
  Lista<int> * b = new Lista<int>();
  Lista<int> * c = new Lista<int>();

  a->InsertaInicio(19);
  a->InsertaInicio(8);
  a->InsertaInicio(5);
  a->InsertaInicio(1);
  
  b->InsertaInicio(20);
  b->InsertaInicio(12);
  b->InsertaInicio(10);
  b->InsertaInicio(5);
  b->InsertaInicio(4);
  b->InsertaInicio(3);

  c->InsertaInicio(1);
  c->InsertaInicio(3);
  c->InsertaInicio(2);
  
  a->NodoMayor();
  b->NodoMayor();
  c->NodoMayor();

  return 0;
}

template<class T>
Lista<T> * Mesclar(Lista<T> * L1, Lista<T> * L2){
  Lista<T> * Apun, * Apun1 = L1, * Apun2 = L2;

  Apun = new Lista<T>();
  while((Apun1->RegresaPrimero() != nullptr) || (Apun2->RegresaPrimero() != nullptr)){
    if((Apun1->RegresaPrimero()) && (Apun2->RegresaPrimero())){
      if(Apun1->RegresaInfo() != Apun2->RegresaInfo()){
	if(Apun1->RegresaInfo() < Apun2->RegresaInfo()){
	  Apun->InsertaFinal(Apun1->RegresaInfo());
	  Apun1->AsigNodo(Apun1->RegresaPrimSig());
	}
	else{
	  Apun->InsertaFinal(Apun2->RegresaInfo());
	  Apun2->AsigNodo(Apun2->RegresaPrimSig());
	}
      }
      else{
	Apun->InsertaFinal(Apun1->RegresaInfo());
	Apun1->AsigNodo(Apun1->RegresaPrimSig());
	Apun2->AsigNodo(Apun2->RegresaPrimSig());
      }
    }else{
      if(Apun1->RegresaPrimero()){
	Apun->InsertaFinal(Apun1->RegresaInfo());
	Apun1->AsigNodo(Apun1->RegresaPrimSig());
      }
      if(Apun2->RegresaPrimero()){
	Apun->InsertaFinal(Apun2->RegresaInfo());
	Apun2->AsigNodo(Apun2->RegresaPrimSig());
      }
    }
  }
  return Apun;
}
