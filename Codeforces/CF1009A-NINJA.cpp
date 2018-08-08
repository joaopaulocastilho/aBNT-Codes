#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n, m, ans = 0, i, aux;
  queue<int> wallet, games;

  scanf("%d %d", &n, &m);
  for(i = 0; i < n; i++){
    scanf("%d", &aux);
    games.push(aux);
  }
  for(i = 0; i < m; i++){
    scanf("%d", &aux);
    wallet.push(aux);
  }
  while(!games.empty() && !wallet.empty()){
    if(wallet.front() >= games.front()){
      wallet.pop(); games.pop();
      ans++;
    }
    else games.pop();
  }
  printf("%d\n", ans);
  
  return 0;
}
