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
NodoArbolBal<T>::NodoArbolBal(){
  HijoDer = nullptr;
  HijoIzq = nullptr;
}

template <class T>
T NodoArbolBal<T>::RegresaInfo(){
  return Info;
}

template <class T>
void NodoArbolBal<T>::ActulizaInfo(T Dato){
  Info = Dato;
}

/*
 *Declaracion de la clase ArbolBalanceado
 * */

template <class T>
class ArbolBalanceado{
  private:
    NodoArbolBal<T> * Raiz;
    int Band;
    void InsertaBalanceado(T, NodoArbolBal<T> *, int *);
    void Imprime(NodoArbolBal<T> *);
  public:
    ArbolBalanceado();
    NodoArbolBal<T> * RegresaRaiz();
    NodoArbolBal<T> * Busca(NodoArbolBal<T> *, T);
    void InsertaBalanceado(T Dato){InsertaBalanceado(Dato, Raiz, &Band);}
    
    NodoArbolBal<T> * RotacionHI_HD(NodoArbolBal<T> *, NodoArbolBal<T> *);
    NodoArbolBal<T> * RotacionHD_HI(NodoArbolBal<T> *, NodoArbolBal<T> *);
    NodoArbolBal<T> * RotacionHI_HI(NodoArbolBal<T> *, NodoArbolBal<T> *);
    NodoArbolBal<T> * RotacionHD_HD(NodoArbolBal<T> *, NodoArbolBal<T> *);

    /*NodoArbolBal<T> *RestructuraI(NodoArbolBal<T> *, int *);
    NodoArbolBal<T> *RestructuraD(NodoArbolBal<T> *, int *);
    void EliminaBalanceado(NodoArbolBal<T> *, NodoArbolBal<T> *, int *, T);
    void Sustituye(NodoArbolBal<T> *, NodoArbolBal<T> *, int *);*/
    void Imprime(){Imprime(Raiz);}
};	

template <class T>
ArbolBalanceado<T>::ArbolBalanceado(){
  Raiz = nullptr;
  Band = 0;
}

template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RegresaRaiz(){
  return Raiz;
}

template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RotacionHI_HI(NodoArbolBal<T> *Apunt, NodoArbolBal<T> * ApAux1){
  Apunt->HijoIzq = ApAux1->HijoDer;
  ApAux1->HijoDer = Apunt;
  Apunt->FE = 0;
  return ApAux1;
}

template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::Busca(NodoArbolBal<T> * Apunt, T Dato){
  if(Apunt != nullptr){
    if(Apunt->Info == Dato)
      return Apunt;
    else{
      if(Apunt->Info > Dato)
	return Busca(Apunt->HijoIzq, Dato);
      else
	return Busca(Apunt->HijoDer, Dato);
    }
  }
  else
    return nullptr;
}

template <class T>
void ArbolBalanceado<T>::Imprime(NodoArbolBal<T> * Apunt){
  if(Apunt != nullptr){
    Imprime(Apunt->HijoIzq);
    std::cout << Apunt->Info << std::endl << std::endl;
    Imprime(Apunt->HijoDer);
  }
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
  ApAux2 = ApAux1->HijoIzq;                       
  Apunt->HijoDer = ApAux2->HijoIzq;
  ApAux2->HijoIzq = Apunt;
  ApAux1->HijoIzq = ApAux2->HijoDer;              
  ApAux2->HijoDer = ApAux1;                       
  if(ApAux2->FE == 1)
    Apunt->FE = -1;
  else                                        
    Apunt->FE = 0;                                
  if(ApAux2->FE == -1)                               
    ApAux1->FE = 1;                               
  else                                              
    ApAux1->FE = 0;                                
  return ApAux2;
}

template <class T>
void ArbolBalanceado<T>::InsertaBalanceado(T Dato, NodoArbolBal<T> * Apunt, int *Band){
  NodoArbolBal<T> * ApAux1, * ApAux2;
  if(Apunt != nullptr){
    if(Dato < Apunt->Info){
      InsertaBalanceado(Dato, Apunt->HijoIzq, Band);
      Apunt->HijoIzq = Raiz;
      if(0 < *Band)
	switch(Apunt->FE){
	  case 1:{
		   Apunt->FE = 0;
		   *Band = 0;
		   break;
		 }
	  case 0:{
		   Apunt->FE = -1;
		   break;
		 }
	  case -1:{
		    ApAux1 = Apunt->HijoIzq;
		    if(ApAux1->FE <= 0)
		      Apunt = RotacionHI_HI(Apunt, ApAux1);
		    else
		      Apunt = RotacionHI_HD(Apunt, ApAux1);
		    Apunt->FE = 0;
		    *Band = 0;
		  }
	}
    }
    else
      if(Dato > Apunt->Info){
	InsertaBalanceado(Dato, Apunt->HijoDer, Band);
	Apunt->HijoDer = Raiz;
	if(0 < *Band)
	  switch(Apunt->FE){
	    case -1:{
		      Apunt->FE = 0;
		      *Band = 0;
		      break;
		    }
	    case 0:{
		     Apunt->FE = 1;
		     break;
		   }
	    case 1:{
		     ApAux1 = Apunt->HijoDer;
		     if(ApAux1->FE >= 0)
		       Apunt = RotacionHD_HD(Apunt, ApAux1);
		     else
		       Apunt = RotacionHD_HI(Apunt, ApAux1);
		     Apunt->FE = 0;
		     *Band = 0;
		   }

	  }
      }
    Raiz = Apunt;
  }
  else{
    ApAux2 = new NodoArbolBal<T>();
    ApAux2->Info = Dato;
    ApAux2->FE = 0;
    *Band = 1;
    Raiz = ApAux2;
  }
}

// Eliminacion de arbolesBalanceados Pg. 371





#endif
















