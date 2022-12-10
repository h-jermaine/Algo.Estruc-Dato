#ifndef CLIENTEBANCO_H_
#define CLIENTEBANCO_H_
#include <string>

int menu(){
  int Opcion;
  do{
    std::cout << "\n\n\t\tOpciones de trabajo.\n\n\n";
    std::cout << "(1) Dar de alta Cliente nuevo.\n";
    std::cout << "(2) Lee datos de clientes en un txt.\n";
    std::cout << "(3) Reporte de todos los clientes ordenados por numero de cliente.\n";
    std::cout << "(4) Reporte de todos los clientes ordenados por numero de cliente en txt.\n";
    std::cout << "(5) Reporte de clientes con antiguedad mayor a 5 anyos.\n";
    std::cout << "(6) Reporte de clientes con cuentas diferentes mayores a 2.\n\n";
    std::cout << "(7) Dar de baja a cliente registrago.";
    std::cout << "(8) "
    std::cout << "(6) Terminar la opcion seleccionada: ";
    std::cin >> Opcion;
  }while(Opcion > 6 || Opcion < 1);
  return Opcion;
}

class Fabrica{
  private:
    int Clave;
    std::string Nombre, Domicilio, Telefono;
  public:
    Fabrica();
    Fabrica(int, std::string, std::string, std::string);
    void CambiaDomic(std::string);
    void CambiaTelf(std::string);
    int operator > (Fabrica);
    int operator < (Fabrica);
    int operator == (Fabrica);
    friend istream & operator >> (istream &, Fabrica &);
    friend ostream & operator << (ostream &, Fabrica &);
};

Fabrica::Fabrica(){
  Clave = 0;
  Nombre = Domicilio = Telefono = "";
}

Fabrica::Fabrica(int Cla, std::string Nom, std::string Domic, std::string Tel){
  Clave = Cla;
  Nombre = Nom;
  Domicilio = Domic;
  Telefono = Tel;
}

void Fabrica::CambiaDomic(std::string NuevoDom){
  Domicilio = NuevoDom;
}

void Fabrica::CambiaTelf(std::string NuevoTel){
  Telefono = NuevoTel;
}

int Fabrica::operator > (Fabrica ObjFab){
  if(Clave > ObjFab.Clave)
    return 1;
  else
    return 0;
}

int Fabrica::operator < (Fabrica ObjFab){
  if(Clave < ObjFab.Clave)
    return 1;
  else
    return 0;
}

int Fabrica::operator == (Fabrica ObjFab){
  if(Clave == ObjFab.Clave)
    return 1;
  else
    return 0;
}

istream & operator >> (istream & Lee, Fabrica & ObjFab){
  std::cout<<"\n\nIngrese Nombre de la fabrica: ";
  std::Lee>>ObjFab.Nombre;
  std::cout<<"\n\nIngrese clave de la Fabrica: ";
  std::Lee>>ObjFab.Clave;
  std::cout<<"\n\nIngrese Domicilio de la fabrica: ";
  std::Lee>> ObjFab.Domicilio;
  std::cout<<"\n\nIngrese telefono de la fabrica: ";
  std::Lee>> ObjFab.Telefono;
  return Lee;
}

ostream & operator << (ostream & Escribe, Fabrica & ObjFab){
  std::cout << "\n\nDatos de la fabrica\n";
  std::Escribe << "Nombre:  " << ObjFab.Nombre << std::endl;
  std::Escribe << "Clave:  " << ObjFab.Clave << std::endl;
  std::Escribe << "Domicilio:  " << ObjFab.Clave << std::endl;
  std::Escribe << "Telefono:  " << ObjFab.Telefono << std::endl;
  return Escribe;
}

#endif
