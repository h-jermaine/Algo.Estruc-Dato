#include <iostream>
#include "ListaDobLiga.h"
using namespace std;
int main(){
    ListaDobLiga<int> * L = new ListaDobLiga<int>();
    L->InsertaOrdenado(2);
    L->InsertaOrdenado(5);
    L->InsertaOrdenado(42);
    L->InsertaOrdenado(27);
    cout << L->EliminaPrimero() << endl;
    L->m();
    //cout << L->r() << endl;
    return 0;
}
