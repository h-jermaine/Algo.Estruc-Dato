#include <iostream>
#include "ListaDobLiga.h"
#include <map>
using namespace std;

template<class T>
ListaDobLiga<T> * sha1(ListaDobLiga<T> *);

template<class T>

ListaDobLiga<T> * sha2(ListaDobLiga<T> *);

int main(){
  ListaDobLiga<char> * X = new ListaDobLiga<char>();
  ListaDobLiga<char> * X1 = new ListaDobLiga<char>();
  ListaDobLiga<char> * X2 = new ListaDobLiga<char>();
  string cod = "Anacleto, agente secreto";
  for(int i = 0; i < cod.length(); i++)
    X->InsertaFinal(cod[i]);
  X1 = sha1(X);
  X2 = sha2(X1);
  X2->ms();
  return 0;
}

template<class T>
ListaDobLiga<T> * sha1(ListaDobLiga<T> * Lc){
  ListaDobLiga<T> * aux = new ListaDobLiga<T>();
  map<int, char> vocl;
  vocl[65] = 'A';
  vocl[69] = 'E';
  vocl[73] = 'I';
  vocl[79] = 'O';
  vocl[85] = 'U';
  vocl[97] = 'a';
  vocl[101] = 'e';
  vocl[105] = 'i';
  vocl[111] = 'o';
  vocl[117] = 'u';
  NodoDobleLiga<T> * tmp1 = Lc->RetornaPrimero();
  NodoDobleLiga<T> * tmp2 = Lc->RetornaLigaDer();
  while(tmp1){
    if(vocl[int(tmp1->Info)] || vocl[int(tmp2->Info)])
      aux->InsertaFinal(tmp1->Info);
    else{
      aux->InsertaFinal(tmp2->Info);
      aux->InsertaFinal(tmp1->Info);
      if(tmp1)
	tmp1 = tmp1->LigaDer;
      if(tmp2)
	tmp2 = tmp2->LigaDer;
    }
    if(tmp1)
      tmp1 = tmp1->LigaDer;
    if(tmp2)
      tmp2 = tmp2->LigaDer;
  }
  return aux;
}

template<class T>
ListaDobLiga<T> * sha2(ListaDobLiga<T> * Lc){
  ListaDobLiga<T> * c_py = new ListaDobLiga<T>();
  NodoDobleLiga<T> * C = Lc->RetornaPrimero();
  while(C){
    c_py->InsertaFinal(C->Info);
    C = C->LigaDer;
  }
  ListaDobLiga<T> * aux = new ListaDobLiga<T>();
  while(c_py->RetornaPrimero()){
      aux->InsertaFinal(c_py->RetornaInfoPrimero());
      aux->InsertaFinal(c_py->RetornaInfoUltimo());
      c_py->EliminaUltimo();
      c_py->EliminaPrimero();
  }
  return aux;
}
