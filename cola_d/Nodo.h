#ifndef NODO_H_
#define NODO_H_
class Nodo{
private:
  int dato;
  Nodo *sig;
public:
  Nodo(int dato = 0, Nodo *sig = nullptr);
  int ret_dato();
  Nodo *ret_sig(){
    return this->sig;
  }
  void asig_dato(int dato);
  void asig_sig(Nodo *sig);
};

Nodo::Nodo(int dato, Nodo *sig){
  this->dato = dato;
  this->sig = sig;
}

int Nodo::ret_dato(){
return this->dato;
}

void Nodo::asig_dato(int dato){
  this->dato = dato;
}

void Nodo::asig_sig(Nodo *sig){
  this->sig = sig;
}

#endif
