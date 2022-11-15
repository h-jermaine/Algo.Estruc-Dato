#ifndef ARBOLBALANCEADO_H_
#define ARBOLBALANCEADO_H_
template <class T>
class ArbolBalanceado;

template <class T>
class NodoArbolBal{
  private:
    NodoArbolBal<T> * HijoIzq;
    NodoArbolBal<T> * HijoDer;
    T Info;
    int FE;
  public:
    NodoArbolBal();
    T RegresaInfo();
    void ActulizaInfo(T);
    friend class ArbolBalanceado<T>;
};

template <class T>
class ArbolBalanceado{
  private:
    NodoArbolBal<T> * Raiz;
  public:
    ArbolBalanceado();
};

template <class T>
ArbolBalanceado<T>::ArbolBalanceado(){
  Raiz = nullptr;
}

template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RotacionHI_HI(NodoArbolBal<T> *Apunt, NodoArbolBal<T> * ApAux1){
  Apunt->HijoIzq = ApAux1->HijoDer;
  ApAux1->HijoDer = Apunt;
  Apunt->FE = 0;
  return ApAux1;
}

template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RotacionHD_HD(NodoArbolBal<T> *Apunt, NodoArbolBal<T> *ApAux1){                                        
  Apunt->HijoDer = ApAux1->HijoIzq;
  ApAux1->HijoIzq = Apunt;                    
  Apunt->FE = 0;                              
  return ApAux1;
}

template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RotacionHI_HD(NodoArbolBal<T> *Apunt, NodoArbolBal<T> *ApAux1){                               
  NodoArbolBal<T> * ApAux2;
  ApAux2 = ApAux1->HijoDer;
  Apunt->HijoIzq = ApAux2->HijoDer;
  ApAux2->HijoDer = Apunt;
  ApAux1->HijoDer = ApAux2->HijoIzq;
  ApAux2->HijoIzq = ApAux1;
  if(ApAux2->FE == -1)
    Apunt->FE = 1;
  else
    Apunt->FE = 0;
  if(ApAux2->FE == 1)
    Apunt->FE = -1;
  else
    Apunt->FE = 0;
  return ApAux2;
}

template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RotacionHD_HI(NodoArbolBal<T> * Apunt, NodoArbolBal<T> * ApAux1){
  NodoArbolBal<T> * ApAux2;
  ApAux2 = ApAux1->HijoIzq;                       Apunt->HijoDer = ApAux2->HijoIzq;
  ApAux2->HijoIzq = Apunt
  ApAux1->HijoIzq = ApAux2->HijoDer;              ApAux2->HijoDer = ApAux1;                       if(ApAux2->FE == -1)
    Apunt->FE = 1;
  else                                        
    Apunt->FE = 0;                                if(ApAux2->FE == 1)                               Apunt->FE = -1;                               else                                              Apunt->FE = 0;                                return ApAux2;
}






#endif
