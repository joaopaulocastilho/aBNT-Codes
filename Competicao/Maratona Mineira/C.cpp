#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
  int n; cin >> n;
  int um, dois, tres, quatro, cinco, seis;
  um = dois = tres = quatro = cinco = seis = 0;
  while(n--){
    int num;
    cin >> num;
    um += num != 1 ? (num+1 == 7 ? 2 : 1) : 0;
    dois += num != 2 ? (num+2 == 7 ? 2 : 1) : 0;
    tres += num != 3 ? (num+3 == 7 ? 2 : 1) : 0;
    quatro += num != 4 ? (num+4 == 7 ? 2 : 1) : 0;
    cinco += num != 5 ? (num+5 == 7 ? 2 : 1) : 0;
    seis += num != 6 ? (num+6 == 7 ? 2 : 1) : 0;
  }
  cout << min(um, min(dois, min(tres, min(quatro, min(cinco, seis))))) << endl;
  return 0;
}
