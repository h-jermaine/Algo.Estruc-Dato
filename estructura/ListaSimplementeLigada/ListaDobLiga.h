#ifndef LISTADOBLIGA_H_
#define LISTADOBLIGA_H_
#include <iostream>
template<class T>
class ListaDobLiga;

template<class T>
class NodoDobleLiga{
  public: 
    NodoDobleLiga<T> * LigaIzq;
    NodoDobleLiga<T> * LigaDer;
    T Info;
  NodoDobleLiga();
  friend class ListaDobLiga<T>;
};

template<class T>
NodoDobleLiga<T>::NodoDobleLiga(){
  LigaIzq = nullptr;
  LigaDer = nullptr;
}

template<class T>
class ListaDobLiga{
  private:
    NodoDobleLiga<T> * Primero;
    NodoDobleLiga<T> * Ultimo;
  public:
    ListaDobLiga();
    void InsertaInicio(T);
    void InsertaFinal(T);
    void InsertaOrdenado(T);
    int EliminaPrimero();
    int EliminaUltimo();
    int EliminaUnNodo(T);
    void m(){
        NodoDobleLiga<T> * tmp = Primero;
        while(tmp){
            std::cout << tmp->Info << std::endl;
            tmp = tmp->LigaDer;
        }
    }
    void ms(){
      NodoDobleLiga<T> * tmp = Primero;
      while(tmp){
	std::cout << tmp->Info;
	tmp = tmp->LigaDer;
      }
      std::cout << std::endl;
    }
    T RetornaInfoPrimero(){
        return Primero->Info;
    }
    T RetornaInfoUltimo(){
      return Ultimo->Info;
    }
    NodoDobleLiga<T> *RetornaPrimero(){
      return Primero;
    }
    NodoDobleLiga<T> * RetornaUltimo(){
      return Ultimo;
    }
    NodoDobleLiga<T> * RetornaLigaDer(){
      return Primero->LigaDer;
    }
    void AsignarDer(NodoDobleLiga<T> * Nd){
      Primero = Nd;
    }
};

template<class T>
ListaDobLiga<T>::ListaDobLiga(){
    Primero = nullptr;
    Ultimo = nullptr;
}

//  Insersion al principio de la lista
template<class T>
void ListaDobLiga<T>::InsertaInicio(T Dato){
  NodoDobleLiga<T> * Apunt = new NodoDobleLiga<T>();
  Apunt->Info = Dato;
  Apunt->LigaDer = Primero;
  if(Primero)
    Primero->LigaIzq = Apunt;
  else
    Ultimo = Apunt;
  Primero = Apunt;
}

//  Insercion al final de la lista
template<class T>
void ListaDobLiga<T>::InsertaFinal(T Dato){
  NodoDobleLiga<T> * Apunt = new NodoDobleLiga<T>();
  Apunt->Info = Dato;
  Apunt->LigaIzq = Ultimo;
  if(Ultimo)
    Ultimo->LigaDer = Apunt;
  else
    Primero = Apunt;
  Ultimo = Apunt;
}

//  Insercion formando una lista ordenada;
template<class T>
void ListaDobLiga<T>::InsertaOrdenado(T Dato){
  NodoDobleLiga<T> * Apunt1, * Apunt2, * Apunt3;
  if(!Primero || Dato < Primero->Info)
    InsertaInicio(Dato);
  else
    if(Dato > Ultimo->Info)
      InsertaFinal(Dato);
    else{
      Apunt1 = new NodoDobleLiga<T>;
      Apunt1->Info = Dato;
      Apunt2 = Primero;
      while(Apunt2->Info < Apunt1->Info)
	Apunt2 = Apunt2->LigaDer;
      Apunt3 = Apunt2->LigaIzq;
      Apunt3->LigaDer = Apunt1;
      Apunt1->LigaDer = Apunt2;
      Apunt1->LigaIzq = Apunt3;
      Apunt2->LigaIzq = Apunt1;
    }
}

//  Eliminacion del primer elemento de la lista
template<class T>
int ListaDobLiga<T>::EliminaPrimero(){
  NodoDobleLiga<T> * Apunt;
  int Resp = 1;
  if(Primero){
    Apunt = Primero;
    if(Apunt->LigaDer){
      Primero = Apunt->LigaDer;
      Primero->LigaIzq = nullptr;
    }
    else{
      Primero = nullptr;
      Ultimo = nullptr;
    }
    delete (Apunt);
  }
  else
    Resp = 0;
  return Resp;
}

//  Eliminacion del ultimo elemento de la lista
template<class T>
int ListaDobLiga<T>::EliminaUltimo(){
  NodoDobleLiga<T> * Apunt;
  int Resp = 1;
  if(Ultimo){
    Apunt = Ultimo;
    if(Apunt->LigaIzq){
      Ultimo = Apunt->LigaIzq;
      Ultimo->LigaDer = nullptr;
    }
    else{
      Primero = nullptr;
      Ultimo = nullptr;
    }
    delete (Apunt);
  }
  else
    Resp = 0;
  return Resp;
}

//  Eliminacion de un elemento de la lista
template<class T>
int ListaDobLiga<T>::EliminaUnNodo(T Dato){
  NodoDobleLiga<T> * Apunt1, * Apunt2, * Apunt3;
  int Resp = 1;
  if(Primero){
    Apunt1 = Primero;
    while((Apunt1 != nullptr) && (Apunt1->Info != Dato))
      Apunt1 = Apunt1->LigaDer;
    if(Apunt1 == nullptr)
      Resp = 0;
    else{
      if(Apunt1 == Primero){
	Primero = Apunt1->LigaDer;
	Primero->LigaIzq = nullptr;
      }
      else{
	if(Apunt1 == Ultimo){
	  Ultimo = Apunt1->LigaIzq;
	  Ultimo->LigaDer = nullptr;
	}
	else{
	  Apunt2 = Apunt1->LigaIzq;
	  Apunt3 = Apunt1->LigaDer;
	  Apunt2->LigaDer = Apunt3;
	  Apunt3->LigaIzq = Apunt2;
	}
	delete (Apunt1);
      }
    }
  }
  else
    Resp = -1;
  return Resp;
}
#endif
