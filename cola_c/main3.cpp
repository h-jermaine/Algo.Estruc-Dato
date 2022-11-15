#include <iostream>
#include <math.h>
#include "Nodo.h"
#include "Cola.h"
//#include "Cola2.h"
#include "Pila.h"
using namespace std;
class Impresion{
public:
  string nombre_archivo;
  string autor;
  string hora_de_encolar;
  Impresion(string n_a = "", string a = "", string h_e = "")
    :nombre_archivo(n_a), autor(a), hora_de_encolar(h_e){}
};
int main(){
  Cola <Impresion>* c = new Cola<Impresion>();
  /*Impresion a("nombre", "marshall", "00:26");
  Impresion b("nombre", "marshall2", "00:45");
  c->insertar(a);
  c->insertar(b);*/
  char d;
  do{
    cout << "Insertar a o b = ";
    cin >> d;
    if(d == 'a'){
      string n_a; string a; string h_e; 
      cout << "ingrese su nombre de archivo:\n";
      cin.ignore();
      getline(cin, n_a);
      cout << "Ingrese al autor:\n";
      getline(cin, a);
      cout << "Ingrese hora de encolar:\n";
      getline(cin, h_e);
      Impresion aux (n_a, a, h_e);
      c->insertar(aux);
    }
    if(d == 'b'){
      if(c->ret_cp()){
	cout << c->ret_p().autor << endl;
	c->eliminar();
      }else{
	cout << "Error 404\n";
      }
    }
  }while((d == 'a') || (d == 'b'));
  return 0;
}
