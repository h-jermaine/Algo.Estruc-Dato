#include <iostream>
using namespace std;
int main(){
  int x, y;
  float p = 0.0;
  float total = 0.0;
  for(int i = 0; i < 2; i++){
    cin >> x >> y >> p;
    total += p * y;
  }
  cout << "VALOR A PAGAR: R$ " << total << endl;
  return 0;
}
