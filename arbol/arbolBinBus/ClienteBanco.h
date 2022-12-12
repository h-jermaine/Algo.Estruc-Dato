#ifndef CLIENTEBANCO_H_
#define CLIENTEBANCO_H_
#include <string>
#include <map>
#include "ArbolBinBusqueda.h"

int Menu(){
  int Opcion;
  do{
    std::cout << "\n\n\t\tOpciones de trabajo.\n\n\n";
    std::cout << "(1) Generar un reporte de todos los clientes de un banco, ordenados por su numero de clientes.\n";
    std::cout << "(2) Generar un reporte de todos los clientes mayores a 5 anyos.\n";
    std::cout << "(3) Generar un reporte de clientes que tengan como minimo dos cuentas diferentes.\n";
    std::cout << "(4) Dar de alta un nuevo cliente.\n";
    std::cout << "(5) Dar de baja a un cliente por numero de clinte.\n";
    std::cout << "(6) Actilizar saldo de Algunos clientes con numero de clinte y numero cuenta.\n";
    std::cout << "(7) Terminar la opcion seleccionada: ";
    std::cin >> Opcion;
  }while(Opcion > 7 || Opcion < 1);
  return Opcion;
}

class ClienteBanco{
  //private:
  public:
    int Tiempo;
    std::map<std::string, int> NumeroCuenta;
    int NumeroCliente;
  //public:
    ClienteBanco();
    ClienteBanco(int, std::string, int, int);
    int operator > (ClienteBanco);
    int operator < (ClienteBanco);
    int operator == (ClienteBanco);
    friend std::istream & operator >> (std::istream &, ClienteBanco &);
    friend std::ostream & operator << (std::ostream &, ClienteBanco &);
};

ClienteBanco::ClienteBanco(){}

ClienteBanco::ClienteBanco(int NumCli, std::string NumCue, int Cantidad, int Tmp){
  NumeroCliente = NumCli;
  NumeroCuenta.insert(std::pair<std::string, int>(NumCue, Cantidad));
}

int ClienteBanco::operator > (ClienteBanco ObjCli){
  if(NumeroCliente > ObjCli.NumeroCliente)
    return 1;
  else
    return 0;
}

int ClienteBanco::operator < (ClienteBanco ObjCli){
  if(NumeroCliente < ObjCli.NumeroCliente)
    return 1;
  else
    return 0;
}

int ClienteBanco:: operator == (ClienteBanco ObjCli){
  if(NumeroCliente == ObjCli.NumeroCliente)
    return 1;
  else
    return 0;
}

std::istream & operator >> (std::istream & Lee, ClienteBanco & ObjCli){
  std::string NumCue;
  int Monto;
  std::cout << "\n\nIngrese el numero de cliente: ";
  Lee >> ObjCli.NumeroCliente;
  std::cout << "\n\nIngrese el numero de cuenta: ";
  Lee >> NumCue;
  std::cout << "\n\nIngrese el monto de la cuenta: ";
  Lee >> Monto;
  std::cout << "\n\nIngrese el tiempo: ";
  Lee >> ObjCli.Tiempo;
  ObjCli.NumeroCuenta.insert(std::pair<std::string, int>(NumCue, Monto));
  return Lee;
}

std::ostream & operator << (std::ostream & Escribe, ClienteBanco & ObjCli){
  std::cout << "\n\nDatos del cliente\n";
  Escribe << "\n\nNumero de cliente: " << ObjCli.NumeroCliente << std::endl;
  for(auto itr = ObjCli.NumeroCuenta.begin(); itr != ObjCli.NumeroCuenta.end(); ++itr)
    Escribe << "Numero de cuenta: " << itr->first << '\t' << "Saldo: " << itr->second << std::endl;
  Escribe << "\n\nTiempo: " << ObjCli.Tiempo << std::endl;
  return Escribe;
}

void ImprimeClientes(NodoArbol<ClienteBanco> *Apunt){
  if(Apunt){
    ImprimeClientes(Apunt->HijoIzq);
    if(Apunt->RegresaInfo().Tiempo > 5)
      std::cout << Apunt->Info;
    ImprimeClientes(Apunt->HijoDer);
  }
}

void ImprimeCuentas(NodoArbol<ClienteBanco> *Apunt){
  if(Apunt){
    if(Apunt->Info.NumeroCuenta.size() >= 2){
      ImprimeCuentas(Apunt->HijoIzq);
      std::cout << Apunt->Info;
      ImprimeCuentas(Apunt->HijoDer);
    }
  }
}

void ActualizaSaldo(NodoArbol<ClienteBanco> * Apunt, std::string NumCue, int Saldo){
  Apunt->Info.NumeroCuenta[NumCue] = Saldo;
}

#endif
