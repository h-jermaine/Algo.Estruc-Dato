#ifndef LISTA_H_
#define LISTA_H_
#include "Nodo.h"
#include <iostream>
class Lista{
private:
  Nodo *inicio;
  Nodo *fin;
public:
  Lista();
  Nodo * RetornaMayor(Nodo * Apunt){
    if(Apunt != nullptr)
    return Apunt;
  }
  void insertar_init(int);
  void insertar_ult(int);
  void eliminar_init();
  void eliminar_ult();
  void insertar_entre_dos_n(int);
  void eliminar_entre_dos_n(int);
  Nodo *buscar_elemento(Nodo *);
  Nodo *ret_nodo_elem();
  //retornar el nodo anterior a un elemento encontrado
  //inesrtar despues de que se encuentre un nodo
  //insertar antes de un nodo encontrado
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
