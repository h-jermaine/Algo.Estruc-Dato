#include <iostream>
#include "ArbolBalanceado.h"
using namespace std;

int main(){
  ArbolBalanceado<int> * a1 = new ArbolBalanceado<int>();
  NodoArbolBal<int> * Apunt1;
  int Operac, Val;
  do{
    cout << "(1) Ingresar dato\n";
    cout << "(2) Elimina dato\n";
    cout << "(3) Imprime datos\n";
    cout << "(0) Salir\n";
    cin >> Operac;
    switch(Operac){
      case 1:	{
		  cout << "Ingrese un dato: ";
		  cin >> Val;
		  a1->InsertaBalanceado(Val);
		  break;
		}
      case 2:	{
		  cout << "Ingrese el dato a eliminar: ";
		  cin >> Val;
		  a1->EliminaBalanceado(Val);
		  break;
		}
      case 3:	{
		  a1->Imprime();
		  break;
		}
      default: break;
    }
  }while(Operac != 0);
  return 0;
}
