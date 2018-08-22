#include <iostream>

using namespace std;

int main(void){
  int n; cin >> n;
  int gcasa, gtrabalho, c, t;
  gcasa = gtrabalho = c = t = 0;
  while(n--){
    string ida, volta;
    cin >> ida >> volta;
    if(ida == "chuva"){
      if(c > 0){ c--; t++; }
      else{ gcasa++; t++;}
    }
    if(volta == "chuva"){
      if(t > 0){ t--; c++; }
      else{ gtrabalho++; c++; }
    }
  }
  cout << gcasa << " " << gtrabalho << endl;
  return 0;
}
