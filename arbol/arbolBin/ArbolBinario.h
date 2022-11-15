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
    void Preorden(NodoArbol<T> *&);
    void Postorden(NodoArbol<T> *&);
  public:
    ArbolBinario();
    void InsertarArbol(T Dato){InsertarArbol(Raiz, Dato);}
    void Preorden(){Preorden(Raiz);}
    void Postorden(){Postorden(Raiz);}
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

template <class T>
void ArbolBinario<T>::Preorden(NodoArbol<T> *& Apunt){
  if(Apunt){
    std::cout << Apunt->Info << " ";
    Preorden(Apunt->HijoIzq);
    Preorden(Apunt->HijoDer);
  }
}

template <class T>
void ArbolBinario<T>::Inorden(NodoArbol<T> *& Apunt){
  if(Apunt){
    Inorden(Apunt->HijoIzq);
    std::cout << Apunt->Info << " ";
    Inorden(Apunt->HijoDer);
  }
}

template <class T>
void ArbolBinario<T>::Postorden(){
  if(Apunt){
    Postorden(Apunt->HijoIzq);
    Postorden(Apunt->HijoDer);
    std:: cout << Apunt->Info << " ";
  }
}

template <class T>
NodoArbol<T> * ArbolBinBus<T>::

#endif























