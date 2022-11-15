#ifndef COLA2_H_
#define COLA2_H_
#include "Nodo.h"

template<class T>
class Cola{
private:
  Nodo <T>* primero;
  Nodo <T>* ultimo;
public: 
  Cola();
  void insertar(T);
  void eliminar(); 
  void mostrar(); 
  T ret_p();
  T ret_u();
  Nodo <T>* ret_cp();
  Nodo <T>* ret_cu();
  Cola <T>* el_rep(){
    Cola <T>* aux = new Cola<T>();
    while(primero){
      if(primero->ret_dato() != primero->ret_sig()->ret_dato())
	aux->insertar(primero->ret_dato());
      eliminar();
    }
    return aux;
  }
};

template<class T>
Cola<T>::Cola(){
  primero = ultimo = nullptr;
}

template<class T>
void Cola<T>::insertar(T dato){
  Nodo <T>* aux = new Nodo<T>(dato);
  if((primero == nullptr) && ultimo == nullptr)
    primero = ultimo = aux;
  else{
    ultimo->asig_sig(aux);
    ultimo = aux;
    aux->asig_sig(primero);
  }
}

template<class T>
void Cola<T>::eliminar(){
  if((primero != nullptr) && (ultimo != nullptr)){
    Nodo <T>* aux = primero;
    primero = primero->ret_sig();
    ultimo->asig_sig(primero);
    if(primero == nullptr)
      ultimo = primero;
    if(primero == ultimo)
      primero->asig_sig(nullptr);
    delete aux;
  }
  else{
    Nodo <T>* aux = primero;
    primero = ultimo = nullptr;  
    delete aux;
  }
}

template<class T>
void Cola<T>::mostrar(){
  Nodo <T>* aux = primero;
  while(aux != ultimo){
    std::cout << aux->ret_dato() << std::endl;
    aux = aux->ret_sig();
   }
   std::cout << ultimo->ret_dato() << std::endl;
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
Nodo <T>* Cola<T>::ret_cp(){
  return primero;
}

template<class T>
Nodo <T>* Cola<T>::ret_cu(){
  return ultimo;
}

#endif
