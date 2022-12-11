#include <iostream>
#include <map>
#include "ClienteBanco.h"
#include "ArbolBinBusqueda.h"
using namespace std;

int main(){
  ArbolBinBus<ClienteBanco> ClienteB;
  ClienteBanco CliB;
  int Opc, NumCli;
  string NumCue;
  
  do{
    Opc = Menu();
    switch (Opc){
      case 1:{
               cout << "\n\n\n----------------\n\n";
               cout << "NUMERO DE CLIENTES\n\n";
               cout << "--------------------\n\n";
               ClienteB.Inorden();
               break;
             }
      case 2:{
               NodoArbol<ClienteBanco> *Apunt;
               Apunt = ClienteB.RegrezaRaiz();
               Imprimer(Apunt);
               break;
             }
      case 3:{
               break;
             }
      case 4:{
               cin >> CliB;
               ClienteB.InsertaNodoSinRep(CliB);
               break;
             }
      case 5: 
             cout << "\n\n\nFIN DEL PROCESO.\n\n\n";
             break;
    }
  }while(Opc >= 1 && Opc < 5);
  return 0;
}
