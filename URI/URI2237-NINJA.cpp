#include <bits/stdc++.h>

using namespace std;

typedef pair<int, vector<int>> ivi;

const int MAX = 51234;

int dist[MAX], n = 0;
map<vector<int>, int> state;

int p1[] = {0, 1, 2, 4, 5, 6, 0, 1, 2, 3};
int p2[] = {1, 2, 3, 5, 6, 7, 4, 5, 6, 7};

int dijkstra(vector<int> s){
  int i, j, k, u, d;
  vector<int> tmp;
  priority_queue<ivi, vector<ivi>, greater<ivi> >pq;

  //printf("%d\n", state[tmp]);
  //for(i = 0; i < 8; i++) printf("%d ", s[i]); printf("\n");
  
  memset(dist, -1, sizeof(dist));
  pq.push(ivi(0, s));
  while(!pq.empty()){
    u = state[pq.top().second];
    d = pq.top().first;
    tmp = pq.top().second;
    //printf("%d %d\n", u, d);
    pq.pop();
    if(dist[u] != -1) continue;
    dist[u] = d;
    if(u == 1) break;
    for(i = 0; i < 10; i++){
      j = p1[i]; k = p2[i];
      swap(tmp[j], tmp[k]);
      if(state.find(tmp) == state.end()) state[tmp] = n++;
      pq.push(ivi(d + tmp[j] + tmp[k], tmp));
      swap(tmp[j], tmp[k]);
    }
  }
  return dist[1];
}

int main(void){
  int i, num;
  vector<int> tmp1, tmp2;
  
  for(i = 0; i < 8; i++){
    scanf("%d", &num);
    tmp1.push_back(num);
  }
  for(i = 0; i < 8; i++){
    scanf("%d", &num);
    tmp2.push_back(num);
  }
  state[tmp1] = n++;
  state[tmp2] = n++;
  printf("%d\n", dijkstra(tmp1));
  
  return 0;
}
