#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 112345

#define ll long long int

int main(void){
  ll inicio, fim, espera, arr[MAX], tempoUsado;
  int n, i;
  cin >> inicio;
  cin >> fim;
  cin >> espera;
  tempoUsado = inicio;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    cin >> arr[i];
  }
  for(i = 0; i < n; i++){
    tempoUsado = max(arr[i] + espera, tempoUsado + espera);
    if(tempoUsado > fim-espera) break;
  }
  //  printf("\n");
  if(tempoUsado > fim - espera){
    while(i > 0 && arr[i-1] == (arr[i] - 1)) i = i - 1;
    cout << (arr[i] - 1) << '\n';
  }
  else cout << fim - espera << '\n';
  return 0;
}
