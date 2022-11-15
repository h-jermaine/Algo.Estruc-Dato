#ifndef ARBOLBINBUS_H_
#define ARBOLBINBUS_H_
template <class T>
class ArbolBinBus;

template <class T>
class NodoArbol{
  private:
    T Info;
    NodoArbol<T> * HijoDer;
    NodoArbol<T> * HijoIzq;
  public:
    NodoArbol();
    friend class ArbolBinBus<T>;
};

template <class T>
NodoArbol<T>::NodoArbol(){
  HijoIzq = nullptr;
  HijoDer = nullptr;
}

template <class T>
class ArbolBinBus{
  private:
    NodoArbol<T> * Raiz;
    NodoArbol<T> * Busqueda(NodoArbol<T> *, T);
    void InsertaNodoSinRep(NodoArbol<T> *, T);
  public:
    ArbolBinBus();
    void Busqueda(T);
    void InsertaNodoSinRep(T Dato){InsertaNodoSinRep(Raiz, Dato);}
    T m(){
      return Raiz->Info;
    }
};

template <class T>
ArbolBinBus<T>::ArbolBinBus(){
  Raiz = nullptr;
}

template <class T>
NodoArbol<T> * ArbolBinBus<T>::Busqueda(NodoArbol<T> * Apunt, T Dato){
  if(Apunt){
    if(Dato < Apunt->Info)
      return Busqueda(Apunt->HijoIzq, Dato);
    else{
      if(Dato > Apunt->Info)
	return Busqueda(Apunt->HijoDer, Dato);
      else
	return Apunt;
    }
  }
  else
    return nullptr;
}

template <class T>
void ArbolBinBus<T>::Busqueda(T Dato){
  NodoArbol<T> * Apunt = Busqueda(Raiz, Dato);
  if(Apunt){
    std::cout << "El nodo " << Apunt->Info <<" a sido encontrado" << std::endl;
  }
  else
    std::cout << "No se encontro el nodo" << std::endl;
}

template <class T>
void ArbolBinBus<T>::InsertaNodoSinRep(NodoArbol<T> * Apunt, T Dato){
  NodoArbol<T> * ApAux;
  if(Apunt){
    if(Dato < Apunt->Info){
      InsertaNodoSinRep(Apunt->HijoIzq, Dato);
      Apunt->HijoIzq = Raiz;
    }
    else{
      if(Dato > Apunt->Info){
	InsertaNodoSinRep(Apunt->HijoDer, Dato);
	Apunt->HijoDer = Raiz;
      }
      Raiz = Apunt;
    }
  }
  else{
    ApAux = new NodoArbol<T>();
    ApAux->Info = Dato;
    Raiz = ApAux;
  }
}
#endif





















