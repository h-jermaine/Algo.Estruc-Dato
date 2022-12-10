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
    void EliminaBalanceado(NodoArbolBal<T> *, NodoArbolBal<T> *, int *, T);
  public:
    ArbolBalanceado();
    NodoArbolBal<T> * RegresaRaiz();
    NodoArbolBal<T> * Busca(NodoArbolBal<T> *, T);
    void InsertaBalanceado(T Dato){InsertaBalanceado(Dato, Raiz, &Band);}
    
    NodoArbolBal<T> * RotacionHI_HD(NodoArbolBal<T> *, NodoArbolBal<T> *);
    NodoArbolBal<T> * RotacionHD_HI(NodoArbolBal<T> *, NodoArbolBal<T> *);
    NodoArbolBal<T> * RotacionHI_HI(NodoArbolBal<T> *, NodoArbolBal<T> *);
    NodoArbolBal<T> * RotacionHD_HD(NodoArbolBal<T> *, NodoArbolBal<T> *);

    NodoArbolBal<T> *RestructuraI(NodoArbolBal<T> *, int *);
    NodoArbolBal<T> *RestructuraD(NodoArbolBal<T> *, int *);
    void EliminaBalanceado(T Dato){EliminaBalanceado(Raiz, nullptr, &Band, Dato);}
    void Sustituye(NodoArbolBal<T> *, NodoArbolBal<T> *, int *);
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
    std::cout << "Nodo: " << Apunt->Info << " FE = " <<Apunt->FE << std::endl;
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

//	Eliminacion de arbolesBalanceados Pg. 371

template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RestructuraI(NodoArbolBal<T> * Nodo, int * Aviso){
  NodoArbolBal<T> * ApAux;
  if(*Aviso > 0){
    switch(Nodo->FE){
      case -1:	Nodo->FE = 0;
	       break;
      case 0:	Nodo->FE = 1;
		*Aviso = 0;
		break;
      case 1:	ApAux = Nodo->HijoDer;
		if(ApAux->FE >= 0){	//Rotacion HD-HD
		  Nodo->HijoDer = ApAux->HijoIzq;
		  ApAux->HijoIzq = Nodo;
		  switch(ApAux->FE){
		    case 0:	Nodo->FE = 1;
				ApAux->FE = -1;
				*Aviso = 0;
				break;
		    case 1:	Nodo->FE = 0;
				ApAux->FE = 0;
				break;
		  }
		  Nodo = ApAux;
		}
		else{
		  Nodo = RotacionHD_HI(Nodo, ApAux);
		  Nodo->FE = 0;
		}
		break;
    }
  }
  return Nodo;
}

template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RestructuraD(NodoArbolBal<T> * Nodo, int * Aviso){
  NodoArbolBal<T> * ApAux;
  if(*Aviso > 0){
    switch(Nodo->FE){
      case 1: Nodo->FE = 0;
              break;
      case 0: Nodo->FE = -1;
              break;
      case -1:  ApAux = Nodo->HijoIzq;
                if(ApAux->FE <= 0){
                  Nodo->HijoIzq = ApAux->HijoDer;
                  ApAux->HijoDer = Nodo;
                  switch(ApAux->FE){
                    case 0: Nodo->FE = -1;
                            ApAux->FE = 1;
                            *Aviso = 0;
                            break;
                    case 1: Nodo->FE = 0;
                            ApAux->FE = 0;
                            break;
                  }
                  Nodo = ApAux;
                }
                else{
                  Nodo = RotacionHI_HD(Nodo, ApAux);
                  Nodo->FE = 0;
                }
                break;
    }
  }
  return Nodo;
}

template <class T>
void ArbolBalanceado<T>::Sustituye(NodoArbolBal<T> * Nodo, NodoArbolBal<T> * ApAux, int * Avisa){
  if(Nodo->HijoDer != nullptr){
    Sustituye(Nodo->HijoDer, ApAux, Avisa);
    if(ApAux->HijoIzq == nullptr)
      Nodo->HijoDer = nullptr;
    else
      Nodo->HijoDer = ApAux->HijoIzq;
    Nodo = RestructuraD(Nodo, Avisa);
  }
  else{
    ApAux->Info = Nodo->Info;
    Nodo = Nodo->HijoIzq;
    *Avisa = 1;
  }
  ApAux->HijoIzq = Nodo;
}

template <class T>
void ArbolBalanceado<T>::EliminaBalanceado(NodoArbolBal<T> * Apunt, NodoArbolBal<T> * ApAnt, int * Avisa, T Dato){
  NodoArbolBal<T> * ApAux;
  int  Bandera;
  if(Apunt != nullptr)
    if(Dato < Apunt->Info){
      if(*Avisa > 0)
	      Bandera = 1;
      else
	      if(*Avisa != 0)
	        Bandera = -1;
      *Avisa = -1;
      EliminaBalanceado(Apunt->HijoIzq, Apunt, Avisa, Dato);
      Apunt = RestructuraI(Apunt, Avisa);
      if(ApAnt != nullptr)
	      switch(Bandera){
	        case -1:	ApAnt->HijoIzq = Apunt;
			              break;
	        case 1:	  ApAnt->HijoDer = Apunt;
			              break;
	        default:	break;
	      }
      else
	      Raiz = Apunt;
    }
    else{
      if(Dato > Apunt->Info){
	      if(*Avisa < 0)
	        Bandera = -1;
	      else
	        if(*Avisa != 0)
	          Bandera = 1;
	      *Avisa = 1;
	      EliminaBalanceado(Apunt->HijoDer, Apunt, Avisa, Dato);
	      Apunt = RestructuraD(Apunt, Avisa);
	      if(ApAnt != nullptr)
	        switch(Bandera){
	          case -1:	ApAnt->HijoIzq = Apunt;
			                break;
	          case 1:	ApAnt->HijoDer = Apunt;
			                break;
	          default:	break;
	        }
	      else
	        Raiz = Apunt;
      }
      else{
	      ApAux = Apunt;
	      if(ApAux->HijoDer == nullptr){
	        Apunt = ApAux->HijoIzq;
	          if(*Avisa != 0)
	            if(*Avisa < 0)
	              ApAnt->HijoIzq = Apunt;
	            else
	              ApAnt->HijoDer = Apunt;
	          else
	            if(Apunt == nullptr)
	              Raiz = nullptr;
	            else
	              Raiz = Apunt;
	          *Avisa = 1;
        }
	      else
	        if(ApAux->HijoIzq == nullptr){
	          Apunt = ApAux->HijoDer;
	          if(*Avisa != 0)
	            if(*Avisa < 0)
		            ApAnt->HijoIzq = Apunt;
	            else
		            ApAnt->HijoDer = Apunt;
	          else
	            if(Apunt == nullptr)
		            Raiz = nullptr;
	            else
		            Raiz = Apunt;
	          *Avisa = 1;
          }
          else{
            Sustituye(ApAux->HijoIzq, ApAux, Avisa);
            Apunt = RestructuraI(Apunt, Avisa);
            if(ApAnt != nullptr)
              if(*Avisa <= 0)
                ApAnt->HijoIzq = Apunt;
              else  
                ApAnt->HijoDer = Apunt;
            else  
              Raiz = Apunt;
	        }
      }
    }
  else
    std::cout << "\n\nEl Dato a eliminar no se  encuentra registrado. \n\n";
}
#endif
















