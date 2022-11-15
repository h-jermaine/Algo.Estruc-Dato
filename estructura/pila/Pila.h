#ifndef PILA_H_
#define PILA_H_
#include "Nodo.h"
#include <string>
#include <iostream>

class Pila{
private:
  Nodo *raiz;
public:
  Pila();
  void insertar(int);
  void eliminar();
  int sima();
  //void leer_cad(std::string cad);
  ~Pila();
};

Pila::Pila(){
  raiz = new Nodo();
}

void Pila::insertar(int dato){
  Nodo *aux = new Nodo(dato);
  if(!raiz)
    raiz = aux;
  else{
    aux->asignar_siguiente(raiz);
    raiz = aux;
  }
}

void Pila::eliminar(){
  Nodo * aux = raiz;
  if(raiz){
    raiz = aux->retornar_siguiente();
    delete aux;
  }
  else
    raiz = nullptr;
}
int Pila::sima(){
  return raiz->retornar_dato();
}
/*void Pila::leer_cad(std::string cad){
  int i = 0;
  int j = 0;
  while(cad[i] != '\0'){
    if(cad[i] == '<')
      push(1);
    if(cad[i] == '>'){
      if(raiz->retDato() == 1){
        pop();
        j++;
      }
    }
    i++;
  }
  std::cout << "entre: "<< j << std::endl;
}

int Pila:sima(){
  return raiz->retornar_dato();
}*/

Pila::~Pila(){
}

#endif
