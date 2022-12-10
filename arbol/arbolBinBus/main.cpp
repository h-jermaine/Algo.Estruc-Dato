#include <iostream>
#include "Productos.h"
#include "Fabricas.h"
#include "ArbolBinBusqueda.h"
using namespace std;

int main(){
  ArbolBinBus<Producto> Inventario;
  Producto Prod;
  int Opc, Cla;
  do{
    Opc = Menu();
    switch (Opc){
      case 1:{
               cin >> Prod;
               Inventario.InsertaNodoSinRep(Prod);
               break;
             }
      case 2:{
               cout << "\n\nIngrese la clave del producto a eliminar: ";
               cin >> Cla;
               producto Prod(Cla, "", 0);
               Inventario.EliminaNodo(Prod);
               break;
             }
      case 3:{
               cout << "\n\n\n----------------\n\n";
               cout << "PRODUCTOS EN INVENTARIO\n\n";
               cout << "--------------------\n\n";
               Inventario.Inorden();
               break;
             }
      case 4:{
               cout << "\n\nIngrese la clave del producto a buscar: ";
               cin >> Cla;
               Producto Prod(Cla, "", 0);
               Inventario.Busqueda(Prod);
               break;
             }
      case 5: 
             cout << "\n\n\nFIN DEL PROCESO.\n\n\n";
             break;
    }
  }while(Opc >= 1 && Opc < 5);
  return 0;
}
