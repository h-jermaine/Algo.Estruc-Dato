#ifndef ARBOLBINBUS_H_
#define ARBOLBINBUS_H_
template <class T>
class ArbolBinBus;

template <class T>
class NodoArbol{
  private:
    T Info;
    NodoArbol<T> *HijoDer;
    NodoArbol<T> *HijoIzq;
  public:
    NodoArbol();
    T RegresaInfo();
    void ActulizaInfo(T);
    friend class ArbolBinBus<T>;
};

template <class T>
NodoArbol<T>::NodoArbol(){
  HijoIzq = nullptr;
  HijoDer = nullptr;
}

template <class T>
NodoArbol<T>::RegresaInfo(){
  return Info;
}

template <class T>
void NodoArbol<T>::ActulizaInfo(T Dato){
  Info = Dato;
}

template <class T>
class ArbolBinBus{
  private:
    NodoArbol<T> * Raiz;
    NodoArbol<T> * Busqueda(NodoArbol<T> *, T);
    void Preorden(NodoArbol<T> *);
    void Inorden(NodoArbol<T> *);
    void Postorden(NodoArbol<T> *);
    void InsertaNodoSinRep(NodoArbol<T> *, T);
    void EliminaNodo(NodoArbol<T> *, T);
  public:
    ArbolBinBus();
    NodoArbol<T> *RegrezaRaiz();
    void Preorden(){Preorden(Raiz);}
    void Inorden(){Inorden(Raiz);}
    void Postorden(){Postorden(Raiz);}
    void Busqueda(T);
    void InsertaNodoSinRep(T Dato){InsertaNodoSinRep(Raiz, Dato);}
    void EliminaNodo(T Dato){EliminaNodo(Raiz. Dato);}
};

template <class T>
ArbolBinBus<T>::ArbolBinBus(){
  Raiz = nullptr;
}

template <class T>
NodoArbol<T> *ArbolBinBus<T>::RegrezaRaiz(){
  return Raiz;
}

template <class T>
void ArbolBinBus<T>::Preorden(NodoArbol<T> *Apunt){
  if(Apunt){
    std::cout Apunt->Info << " ";
    Preorden(Apunt->HijoIzq);
    Preorden(Apunt->HijoDer);
  }
}

template <class T>
void ArbolBinBus<T>::Inorden(NodoArbol<T> *Äpunt){
  if(Apunt){
    Inorden(Apunt->HijoIzq);
    std::cout<< Apunt->Info << " ";
    Inorden(Apunt->HijoDer);
  }
}

template <class T>
void ArbolBinBus<T>::Postorden(NodoArbol<T> *Apunt){
  if(Apunt){
    Postorden(Apunt->HijoIzq);
    Postorden(Apunt->HijoDer);
    std::cout<< Apunt->Info << " ";
  }
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
    std::cout << "\n\n\nExiste un producto registrado con esa clave.\n";
    cout << Apunt->Info;
  }
  else
    std::cout << "\n\nNo se ha registrado ningun producto con esa clave.\n";
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

template <class T>
void ArbolBinBus<T>::EliminaNodo(NodoArbol<T> *Apunt, T Dato){
  if(Apunt)
    if(Dato < Apunt->Info){
      EliminaNodo(Apunt->HijoIzq, Dato);
      Apunt->HijoIzq = Raiz;
    }
    else
      if(Dato > Apunt->Info){
        EliminaNodo(Apunt->HijoDer, Dato);
        Apunt->HijoDer = Raiz;
      }
      else{
        NodoArbol<T> *ApAux1, *ApAux2, *ApAux3;
        ApAux3 = Apunt;
        if(!ApAux3->HijoIzq)
          if(!ApAux3->HijoIzq)
            Apunt = nullptr;
          else
            Apunt = ApAux3->HijoIzq;
        else
          if(!ApAux3->HijoIzq)
            Apunt = ApAux3->HijoDer;
          else{
            ApAux1 = ApAux3->HijoIzq;
            ApAux2 = ApAux3;
            while(ApAux1->HijoDer){
              ApAux2 = ApAux1;
              ApAux1 = ApAux1->HijoDer;
            }
            ApAux3->Info = ApAux1->Info;
            if(ApAux3 == ApAux2)
              ApAux3->HijoIzq = nullptr;
            else
              if(!ApAux1->HijoIzq)
                ApAux2->HijoDer = nullptr;
              else
                ApAux2->HijoDer = ApAux1->HijoIzq;
            ApAux3 = ApAux1;
          }
        delete(ApAux3);
      }
  Raiz = Apunt;
}

#endif





















