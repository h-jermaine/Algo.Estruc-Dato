#include <iostream>
#include <map>
#include "ClienteBanco.h"
#include "ArbolBinBusqueda.h"
using namespace std;

int main(){
  ArbolBinBus<ClienteBanco> ClienteB;
  ClienteBanco CliA;
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
               Apunt = ClienteB.RegresaRaiz();
               ImprimeClientes(Apunt);
               break;
             }
      case 3:{
               NodoArbol<ClienteBanco> *Apunt;
               Apunt = ClienteB.RegresaRaiz();
               ImprimeCuentas(Apunt);
               break;
             }
      case 4:{
               ClienteBanco CliB;
               cin >> CliB;
               CliA = CliB;
               ClienteB.InsertaNodoSinRep(CliA);
               break;
             }
      case 5:{ 
               cout << "\nIngrese el numero de cliente: ";
               cin >> NumCli;
               ClienteBanco CliB(NumCli, "0", 0, 0);
               ClienteB.EliminaNodo(CliB);
               break;
             }
      case 6:{
               int Saldo;
               cout << "\nIngrese Numero de cliente: ";
               cin >> NumCli;
               cout << "\nIngrese numero de cuenta: ";
               cin >> NumCue;
               cout << "\nIngrese saldo: ";
               cin >> Saldo;
               NodoArbol<ClienteBanco> *Apunt;
               ClienteBanco CliB(NumCli, "0", 0, 0);
               Apunt = ClienteB.Busqueda(CliB);
               ActualizaSaldo(Apunt, NumCue, Saldo);
               break;
             }
    }
    cin.ignore();
  }while(Opc >= 1 && Opc < 7);
  return 0;
}
