#include <iostream>
#include <string>
#include <vector>
using namespace std;
void insertar(vector<vector<string>> &tabla, int f, int c, string line, string p){
  tabla[f][c] = line;
  /*for(int i = 1; i < p.length(); i++){

  }*/
}

void mostrar(string sn[], int qn[], vector<vector<string>> tabla, int f, int c){
  for(int k = 0; k < c; k++)
    cout << sn[k] << "      ";
  cout << endl;                               
  for(int i = 0; i < f; i++){
    qn [i] = i;
      cout << qn[i] << "  ";
      for(int j = 0; j < c; j++)                        cout << tabla[i][j] << "  ";
      cout << endl;                             
    }
}
