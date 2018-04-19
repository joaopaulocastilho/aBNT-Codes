#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 21

int n, tracks, track[MAX];

typedef struct{
  vector<int> idxs;
  int ans;
} caminho;

caminho backtrack(int idx, caminho way){
  caminho aux1, aux2;
  if(idx >= tracks) return way;
  if(way.ans + track[idx] > n){
    aux1 = way;
    aux1 = backtrack(idx+1, aux1);
    return aux1;
  }
  else{
    aux1 = aux2 = way;
    aux1.idxs.push_back(track[idx]);
    aux1.ans += track[idx];
    aux1 = backtrack(idx+1, aux1);
    aux2 = backtrack(idx+1, aux2);
    if(aux1.ans > aux2.ans) return aux1;
    if(aux1.ans == aux2.ans && aux1.idxs.size() > aux2.idxs.size()) return aux1;
    return aux2;
  }
}

int main(void){
  caminho ans, aux;
  while(scanf("%d %d", &n, &tracks) != EOF){
    ans.idxs.clear();
    ans.ans = -1;
    for(int i = 0; i < tracks; i++){
      scanf("%d", &track[i]);
    }
    for(int i = 0; i < tracks; i++){
      aux.idxs.clear();
      aux.ans = 0;
      aux = backtrack(i, aux);
      if(aux.ans > ans.ans){
	ans = aux;
      }
    }
    for(vector<int>::iterator it = ans.idxs.begin(); it != ans.idxs.end(); ++it)
      printf("%d ", (*it));
    printf("sum:%d\n", ans.ans);
  }
  return 0;
}
