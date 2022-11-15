#ifndef COLA_H_
#define COLA_H_
#include "Nodo.h"
template<class T>
class Cola{
private: 
  Nodo <T>* primero;
  Nodo <T>* ultimo;
public:
  Cola();
  void insertar(T);
  T ret_p();
  T ret_u();
  void eliminar();
  Nodo <T>*ret_cp(){
    return primero;
  }
  Nodo <T>*ret_cu(){
    return ultimo;
  }
};

template<class T>
Cola<T>::Cola(){
  primero = ultimo = nullptr;
}

template<class T>
void Cola<T>::insertar(T d){
  Nodo <T>* aux = new Nodo<T>(d);
  if(!primero)
    primero = ultimo = aux;
  else{
    ultimo->asig_sig(aux);
    ultimo = aux;
  }
}

template<class T>
T Cola<T>::ret_p(){
  return primero->ret_dato();
}

template<class T>
T Cola<T>::ret_u(){
  return ultimo->ret_dato();
}

template<class T>
void Cola<T>::eliminar(){
  Nodo <T>* aux = primero;
  if(primero != ultimo)
    primero = aux->ret_sig();
  else
    primero = ultimo = nullptr;
  delete aux;
}
#endif
