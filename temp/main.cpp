#include <iostream>
#include <string>
#include "resource.h"
#include <vector>
using namespace std;
int main(){
  int fila = 14;
  int colum = 5;
  strind pantalla = "B00001111B";
  string sn [] = {"__","0","1","X","Y","B"};    int qn [14] = {0};
  vector<vector<string>> tabla(fila, vector<string> (colum));

  string line;

  int f, c;
  do{
    cout << "fila: ";
    cin >> f;
    cout << "columna: ";
    cin >> c;
    cin >> line;
    if(line != "\0"){
      insertar(tabla, f, c, line, pantalla);
      cout << pantalla << endl;
      mostrar(sn, qn, tabla, fila, colum);
    }
  }while(line != "s");

  return 0;
}
