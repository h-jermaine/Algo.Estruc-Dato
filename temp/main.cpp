#include <iostream>
#include <vector>
#include <string>
//#include "resource.h"
#include <map>
using namespace std;
int main(){
  map<string, vector<string>> m;
  string line, row;
  do{
    vector<string> t;
    cout << "row: "; 
    getline(cin, row);
    cout << "-> ";
    getline(cin, line);
    t.push_back(line);
    m.insert(pair<string, vector<string>>(row, t));
    if(line == "ver"){
      for(auto itr = m.begin(); itr != m.end(); itr++)
        cout << itr->first << "   ";
      cout << endl;
      for(auto itr = m.begin(); itr != m.end(); itr++){

      }
    }
  }while(line != "exit");
  return 0;
}
