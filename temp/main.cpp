#include <iostream>
using namespace std;

int main(){
  int n;
  cout << "Ingrese datos\n";
  do{
    cin >> n;
    int tmp = 0;
    for(int i = 0; i < n; i ++){
      for(int j = 0; j < n; j ++){
        for(int k = 0; k < j; k++){
          if(j == k || i == k || (n - 1) == i || (n - 1) == j)
            cout << k << " ";
          else
            cout << "+" << " ";
        }
      }
      tmp ++;
      cout << endl;
    }
    cout << endl;
    cout << endl;
  }while(n > 0);
  return 0;
}
