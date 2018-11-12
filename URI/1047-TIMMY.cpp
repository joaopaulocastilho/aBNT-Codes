#include <bits/stdc++.h>

using namespace std;

int main(void){
  int sh, sm, fh, fm;
  int min, difh, horas;
  cin >> sh >> sm >> fh >> fm;
  if(sh == fh && fm == sm){
    cout << "O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n";
    return 0;
  }
  if(sh == fh && sm > fm){
    min = fm - sm;
    cout << "O JOGO DUROU 23 HORA(S) E " << min << " MINUTO(S)\n";
    return 0;
  }
  if(sh > fh) fh += 24;
  difh = fh - sh;
  min = fm + difh*60;
  horas = (min-sm)/60;
  min = (min-sm) %60;
  cout << "O JOGO DUROU " << horas << " HORA(S) E " << min << " MINUTO(S)\n";
  return 0;
}
