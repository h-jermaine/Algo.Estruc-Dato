#ifndef COLA_H_
#define COLA_H_
#include "Nodo.h"
#include <iostream>

class Cola{
private:
  Nodo *primero;
  Nodo *ultimo;
public:
  Cola();
  void insertar(int);
  void eliminar();
  int ret_ultimo(){
    return ultimo->ret_dato();
  }
  Nodo *ret_primero(){
    return primero;
  }
  void vaciar_cola();
  Cola *copiar_cola(Cola *C){
    Cola *aux = new Cola();
    while(C->primero != nullptr){
      int dato = C->primero->ret_dato();
      aux->insertar(dato);
      C->eliminar();
    }
    return aux;
  }
  Cola *mezclar(Cola *C){
    Cola *aux = new Cola();
    int dato = 0;
    while(primero != nullptr){
      if(primero){
	dato = this->primero->ret_dato();
	aux->insertar(dato);
	this->eliminar();
      }
      if(C->primero){
	dato = C->primero->ret_dato();
	aux->insertar(dato);
	C->eliminar();
      }
    }
    return aux;
  }
  void mostrar(){
    Nodo *aux = primero;
    while(aux != nullptr){
      std::cout << aux->ret_dato() << std::endl;
      aux = aux->ret_sig();
    }
  }
};

Cola::Cola(){
  this->primero = nullptr;
  this->ultimo = nullptr;
}

void Cola::insertar(int dato){
  Nodo *aux = new Nodo(dato);
  if(primero == nullptr){
    primero = aux;
    ultimo = aux;
  }
  else{
    ultimo->asig_sig(aux);
    ultimo = aux;
  }
}

void Cola::eliminar(){
  Nodo *aux = primero;
  if(primero != ultimo)
    primero = aux->ret_sig();
  else
    primero = ultimo = nullptr;
  delete aux;   
}

void Cola::vaciar_cola(){
  while(primero != nullptr)
    eliminar();
}


#endif
