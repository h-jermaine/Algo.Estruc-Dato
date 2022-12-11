#ifndef CLIENTEBANCO_H_
#define CLIENTEBANCO_H_
#include <string>
#include <map>
#include "ArbolBinBusqueda.h"

void Imprime(NodoArbol<ClienteBanco> *);
int Menu(){
  int Opcion;
  do{
    std::cout << "\n\n\t\tOpciones de trabajo.\n\n\n";
    std::cout << "(1) Generar un reporte de todos los clientes de un banco, ordenados por su numero de clientes.\n";
    std::cout << "(2) Lee datos de clientes en un txt.\n";
    std::cout << "(3) Reporte de todos los clientes ordenados por numero de cliente.\n";
    std::cout << "(4) Dar de alta un nuevo cliente.\n";
    std::cout << "(5) Reporte de clientes con antiguedad mayor a 5 anyos.\n";
    std::cout << "(6) Reporte de clientes con cuentas diferentes mayores a 2.\n";
    std::cout << "(7) Dar de baja a cliente registrago.\n";
    std::cout << "(8) Actulizar el saldo de de algunas cuentas de los clientes.\n";
    std::cout << "(9) Actulizar los datos personales.\n\n";
    std::cout << "(10) Terminar la opcion seleccionada: ";
    std::cin >> Opcion;
  }while(Opcion > 11 || Opcion < 1);
  return Opcion;
}

class ClienteBanco{
  private:
    int Tiempo;
    std::map<std::string, int> NumeroCuenta;
    int NumeroCliente;
  public:
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

void Imprime(NodoArbol<ClienteBanco> *Apunt){
  if(Apunt){
    Imprime(Apunt->HijoIzq);
    if(Apunt->RegresaInfo().Tiempo > 5)
      std::cout << Apunt->RegresaInfo();
    Imprime(Apunt->HijoDer);
  }
}

#endif
