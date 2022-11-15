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
  void asignar(int dato);
  void eliminar();
  int ret_ultimo(){
    return ultimo->ret_dato();
  }
  int ret_primero(){
    return primero->ret_dato();
  }
  void vaciar_cola();
  Cola *copiar_cola(Cola *C){
    Cola *aux = new Cola();
    while(C->primero != nullptr){
      int dato = C->primero->ret_dato();
      aux->asignar(dato);
      C->eliminar();
    }
    return aux;
  }
  Cola *mezclar(Cola *C){
    Cola *aux = new Cola();
    while(primero != nullptr){
      int dato = this->primero->ret_dato();
      aux->asignar(dato);
      dato = C->primero->ret_dato();
      aux->asignar(dato);
      C->eliminar();
      this->eliminar();
    }
    return aux;
  }
  void mostrar_cola(){
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

void Cola::asignar(int dato){
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
