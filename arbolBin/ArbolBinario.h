#ifndef ARBOLBINARIO_H_
#define ARBOLBINARIO_H_
template <class T>
class ArbolBinario;

template <class T>
class NodoArbol{
  private:
    T Info;
    NodoArbol<T> HijoIzq;
    NodoArbol<T> HijoDer;
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
T NodoArbol<T>:RegresaInfo(){
  return Info;
}

//	Declaracion de la clase ArbolBinario

template <class T>
class ArbolBinario{
  private:
    NodoArbol<T> * Raiz;
  public:
    ArbolBinario();
};

template <class T>
ArbolBinario<T>::ArbolBinario(){
  Raiz = nullptr;
}


#endif























