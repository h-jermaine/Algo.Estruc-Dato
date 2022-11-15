#ifndef HNODE_H_
#define HNODE_H_
template<typename T>
struct Hnode{
  T Dato;
  Hnode<T> * Next;
  Hnode(T Dato = 0, Hnode<T> * n = nullptr){
    this->Dato = Dato;
    Next = n;
  }
};
#endif
