#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair <int, int> ii;

#define MAX 112345

int main(void){
  int i, tc, n, t, m, num, time, side, first = 1, ans[MAX];
  char dir[10];
  vector<queue<ii> > sides;
  queue<int> ferry;
  
  for(tc = 0; tc < 2; tc++) sides.push_back(queue<ii>());
  scanf("%d", &tc);
  while(tc--){
    if(first) first = 0;
    else printf("\n");
    scanf("%d %d %d", &n, &t, &m);
    for(i = 0; i < m; i++){
      scanf("%d %s ", &num, dir);
      if(!strcmp(dir, "left")) sides[0].push({num, i});
      else sides[1].push({num, i});
    }
    //while(!sides[0].empty()) { printf("%d\n", sides[0].front()); sides[0].pop(); } printf("\n");
    //while(!sides[1].empty()) { printf("%d\n", sides[1].front()); sides[1].pop(); }
    time = side = 0;
    while(!sides[0].empty() || !sides[1].empty() || !ferry.empty()){
      //printf("Lado %s, topo %d\n", side ? "DIREITO" : "ESQUERDO", sides[side].size() <= 0 ? -1 : sides[side].front().first);
      while(!ferry.empty()){ ans[ferry.front()] = time ; ferry.pop(); }
      if((sides[side].empty() && !sides[side^1].empty()) ||
	 (!sides[side^1].empty() && sides[side].front().first > time && sides[side].front().first > sides[side^1].front().first)){
	time = max(time, sides[side^1].front().first);
	side = side^1; time += t;
	//printf("Voltando para esperar do outro lado %d\n", time);
      }
      time = max(time, sides[side].front().first);
      while(!sides[side].empty() && sides[side].front().first <= time && ferry.size() < n){
	//printf("Carregando o que chegou as %d ", sides[side].front().first);
	ferry.push(sides[side].front().second); sides[side].pop();
	//printf(", fila: %d\n", sides[side].size());
      }
      side = side^1; time += t;
      //printf("Indo para o outro lado com %d,  %d\n",ferry.size(), time);
    }
    for(i = 0; i < m; i++) printf("%d\n", ans[i]);
  }

  return 0;
}
