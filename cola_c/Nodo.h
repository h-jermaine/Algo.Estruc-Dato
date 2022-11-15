#ifndef NODO_H_
#define NODO_H_
template < class T > 
class Nodo{
private:
  T dato;
  Nodo <T> *sig;
public:
  Nodo <T> (T d){
    this->dato = d;
    this->sig = nullptr;
  }
  void asig_sig (Nodo <T> *n){
    this->sig = n;
  } 
  void asig_dato (T d){
    this->dato = d;
  } 
  T ret_dato (){
    return this->dato;
  }
  Nodo <T>*ret_sig (){
    return sig;
  }
};
#endif
