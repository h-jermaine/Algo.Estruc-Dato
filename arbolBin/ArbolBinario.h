#ifndef ARBOLBINARIO_H_
#define ARBOLBINARIO_H_
template <class T>
class ArbolBinario;

template <class T>
class NodoArbol{
  private:
    T Info;
    NodoArbol<T> * HijoIzq;
    NodoArbol<T> * HijoDer;
  public:
    NodoArbol();
    T RegresaInfo();
    friend class ArbolBinario<T>;
};

template <class T>
NodoArbol<T>::NodoArbol(){
  HijoDer = nullptr;
  HijoIzq = nullptr;
}

template <class T>
T NodoArbol<T>::RegresaInfo(){
  return Info;
}

//	Declaracion de la clase ArbolBinario

template <class T>
class ArbolBinario{
  private:
    NodoArbol<T> * Raiz;
    void InsertarArbol(NodoArbol<T> *&, T);
  public:
    ArbolBinario();
    void InsertarArbol(T Dato){
      InsertarArbol(Raiz, Dato);
    }
    T m(){
      return Raiz->HijoDer->Info;
    }
};

template <class T>
ArbolBinario<T>::ArbolBinario(){
  Raiz = nullptr;
}

template <class T>
void ArbolBinario<T>::InsertarArbol(NodoArbol<T> *& Apunt, T Dato){
  if(Apunt == nullptr){
    NodoArbol<T> * aux = new NodoArbol<T>();
    aux->Info = Dato;
    Apunt = aux;
  }
  else{
    if(Dato < Apunt->Info)
      InsertarArbol(Apunt->HijoIzq, Dato);
    else
      InsertarArbol(Apunt->HijoDer, Dato);
  }
}

#endif























