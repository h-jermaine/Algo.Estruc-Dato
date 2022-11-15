#ifndef NODO_H_
#define NODO_H_
template<typename T>
struct Nodo{
  T dato;
  Nodo<T> * next;
  Nodo(T dato = 0, Nodo<T> * n = nullptr):dato(dato), next(n){}
};
#endif
