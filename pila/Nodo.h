#ifndef NODO_H_
#define NODO_H_
class Nodo{
private:
  int dato;
  Nodo *siguiente;
public:
  Nodo(int dato = 0, Nodo *n = nullptr);
  int retornar_dato();
  void asignar_dato(int);
  Nodo *retornar_siguiente();/*}{
    return this->;
  }*/
  void asignar_siguiente(Nodo *n);
  ~Nodo();
};

Nodo::Nodo(int dato, Nodo *n):dato(dato), siguiente(n){
}

int Nodo::retornar_dato(){
  return dato;
}

void Nodo::asignar_dato(int dato){
  this->dato = dato;
}
void Nodo::asignar_siguiente(Nodo *n){
  this->siguiente = n;
}

Nodo * Nodo::retornar_siguiente(){
  return this->siguiente;
}

Nodo::~Nodo(){
  siguiente = nullptr;
}
#endif
