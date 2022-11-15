#ifndef PILA_H_
#define PILA_H_
#include "Nodo.h"

template<class T>
class Pila{
private:
  Nodo <T>*raiz;
public:
  Pila();
  void insertar(T dato);
  void eliminar();
  T sima();
  Nodo <T>* ret_u(){
    return raiz;
  }
  ~Pila();
};

template<class T>
Pila<T>::Pila(){
  raiz = nullptr;
}

template<class T>
void Pila<T>::insertar(T dato){
  Nodo <T>* new_nodo = new Nodo(dato);
  if(!raiz)
    raiz = new_nodo;
  else{
    new_nodo->asig_sig(raiz);
    raiz = new_nodo;
  }
}

template<class T>
void Pila<T>::eliminar(){
  if(raiz){
    Nodo <T>*new_nodo = raiz;
    raiz = new_nodo->ret_sig();
    delete new_nodo;
  }
  else
    raiz = nullptr;
}

template<class T>
T Pila<T>::sima(){
  return raiz->ret_dato();
}

template<class T>
Pila<T>::~Pila(){
  while(raiz)
    eliminar();
}

#endif
