#ifndef HQUEUE_H_
#define HQUEUE_H_
template<typename T>
class Hqueue{
  private:
    #include "Hnode.h"
    Hnode<T> * Primero, * Ultimo;
  public:
    Hqueue();
    void Insertar(T);
    void Eliminar();
    void mostrar();
    Hnode<T> * RetornaPrimero(){
      return Primero;
    }
    T RetornaDato(){
      return Primero->Dato;
    }
    ~Hqueue();
};

template<typename T>
Hqueue<T>::Hqueue(){
  Primero = Ultimo = nullptr;
}

template<typename T>
void Hqueue<T>::Insertar(T Dato){
  Hnode<T> * aux = new Hnode<T>(Dato);
  if(!Primero)
    Primero = Ultimo = aux;
  else{
    Ultimo->Next = aux;
    Ultimo = aux;
  }
}

template<typename T>
void Hqueue<T>::Eliminar(){
  Hnode<T> * aux = Primero;
  if(Primero)
    Primero = Primero->Next;
  else
    Primero = Ultimo = nullptr;
  delete aux;
}

template<typename T>
void Hqueue<T>::mostrar(){
  if(Primero){
    Hnode<T> * aux = Primero;
    while(aux){
      std::cout << aux->Dato << std::endl;
      aux = aux->Next;
    }
  }
}

template<typename T>
Hqueue<T>::~Hqueue(){
  while(Primero){
    Hnode<T> * aux = Primero;
    delete aux;
    Primero = Primero->Next;
  }
}
#endif
