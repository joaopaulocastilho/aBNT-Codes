#include <bits/stdc++.h>

using namespace std;

const int MAX = 112345;

int n, m;
vector<int> AL[MAX];

int main(void){
  int q, u, v;
  
  scanf("%d %d", &n, &m);
  while(m--){
    scanf("%d %d %d", &q, &u, &v);
    if(q == 1){
      AL[u].push_back(v);
      AL[v].push_back(u);
    }
    else
      printf("%d\n", find(AL[u].begin(), AL[u].end(), v) == AL[u].end() ? 0 : 1); 
  }

  return 0;
}
