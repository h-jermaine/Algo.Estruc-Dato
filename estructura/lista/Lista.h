#ifndef LISTA_H_
#define LISTA_H_
#include <iostream>
template<class T>
class Lista;

template<class T>
class NodoLista{
  private:
    T Info;
    NodoLista<T> * Liga;
  public:
    NodoLista();
    friend class Lista<T>;
};

template<class T>
NodoLista<T>::NodoLista(){
  Liga = nullptr;
}

template<class T>
class Lista{
  private:
    NodoLista<T> * Primero;
  public:
    Lista();
    void InsertaInicio(T);
    void InsertaFinal(T);
    int InsertaAntes(T, T);
    int InsertaDespues(T, T);
    int EliminaPrimero();
    int EliminaUltimo();
    int EliminaUnNodo(T);
    T RegresaInfo();
    NodoLista<T> * RegresaPrimero();
    NodoLista<T> * RegresaPrimSig(){
      return Primero->Liga;
    }
    void AsigNodo(NodoLista<T> * N){
      Primero = N;
    }
    void m(){
      NodoLista<T> * C = Primero;
      while(C){
        std::cout << C->Info << std::endl;
        C = C->Liga;
      }
    }
};

template<class T>
Lista<T>::Lista(){
  Primero = nullptr;
}

//	INSERCION AL INICIO DE LA LISTA
template<class T>
void Lista<T>::InsertaInicio(T Dato){
  NodoLista<T> * P = new NodoLista<T>();
  P->Info = Dato;
  P->Liga = Primero;
  Primero = P;
}


//	INSERCION AL FINAL DE LA LISTA
template<class T>
void Lista<T>::InsertaFinal(T Dato){
  NodoLista<T> * P, * Ultimo;
  P = new NodoLista<T>();
  P->Info = Dato;
  if(Primero){
    Ultimo = Primero;
    while(Ultimo->Liga)
      Ultimo = Ultimo->Liga;
    Ultimo->Liga = P;
  }
  else
    Primero = P;
}

//	INSERCION ANTES DE UN NODO COMO  REFERENCIA
template<class T>
int Lista<T>::InsertaAntes(T Dato, T Ref){
  NodoLista<T> * P, * Ant, * Q;
  int Resp = 1;
  if(Primero){
    Q = Primero;
    while((Q != nullptr) && (Q->Info != Ref)){
      Ant = Q;
      Q = Q->Liga;
    }
    if(Q != nullptr){
      P = new NodoLista<T>();
      P->Info = Dato;
      if(Primero == Q){
        P->Liga = Primero;
        Primero = P;
      }
      else{
        Ant->Liga = P;
        P->Liga = Q;
      }
    }
    else
      Resp = 0;
  }
  else
    Resp = -1;
  return Resp;
}

//	INSERCION ANTES DE UN NODO  DADO COMO REFERENCIA
template<class T>
int Lista<T>::InsertaDespues(T Dato, T Ref){
  NodoLista<T> * Q, * P;
  int Resp = 1;
  if(Primero){
    Q = Primero;
    while((Q != nullptr) && (Q->Info != Ref))
      Q = Q->Liga;
    if(Q != nullptr){
      P = new NodoLista<T>();
      P->Info = Dato;
      P->Liga = Q->Liga;
      Q->Liga = P;
    }
    else
      Resp = 0;
  }
  else
    Resp = -1;
  return Resp;
}

//	ELIMINACION DEL PRIMER NODO  DE LA LISTA
template<class T>
int Lista<T>::EliminaPrimero(){
  NodoLista<T> * P;
  int Resp = 1;
  if(Primero){
    P = Primero;
    Primero = P->Liga;
    delete (P);
  }
  else
    Resp = 0;
  return Resp;
}

//	ELIMINACION DEL ULTIMO NODO DE LA LISTA
template<class T>
int Lista<T>::EliminaUltimo(){
  NodoLista<T> * Ant, * P;
  int Resp = 1;
  if(Primero){
    if(!Primero->Liga){
      delete (Primero);
      Primero = nullptr;
    }
    else{
      P = Primero;
      while(P->Liga){
        Ant = P;
        P = P->Liga;
      }
      Ant->Liga = nullptr;
      delete (P);
    }
  }
  else
    Resp = 0;
  return Resp;
}

//	ELIMINACION DE UN ELEMENTO DE LA LISTA
template<class T>
int Lista<T>::EliminaUnNodo(T Ref){
  NodoLista<T> * P, * Ant;
  int Resp = 1;
  if(Primero){
    P = Primero;
    while((P->Liga) && (P->Info != Ref)){
      Ant = P;
      P = P->Liga;
    }
    if(P->Info != Ref)
      Resp = 0;
    else{
      if(Primero == P)
	Primero = P->Liga;
      else
	Ant->Liga = P->Liga;
      delete (P);
    }
  }
  else
    Resp = -1;
  return Resp;
}

template<class T>
T Lista<T>::RegresaInfo(){
  return Primero->Info;
}

template<class T>
NodoLista<T> * Lista<T>::RegresaPrimero(){
  return Primero;
}

#endif









