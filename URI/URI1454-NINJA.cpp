#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>

#define MAX 112
#define MINF -123456789
using namespace std;

typedef pair<int, int> ii;

int n;
int adj[MAX][MAX], high[MAX], vis[MAX];

void dijkstra(int v){
  int h;

  priority_queue <ii, vector<ii>, greater<ii>> pq; //PQ GREATER JESUS?
  pq.push(ii(MINF , v));
  while(!pq.empty()){
    v = pq.top().second;
    h = pq.top().first;
    //printf("Tirei o %d com h %d\n", v+1, h);
    pq.pop();
    if(vis[v]) continue;
    high[v] = h;
    vis[v] = 1;
    for(int w = 0; w < n; w++)
      if(adj[v][w] != MINF && !vis[w]){
        pq.push(ii(max(h, adj[v][w]), w));
        //printf("o %d botou o %d na fila com altura %d\n", v+1, w+1, max(h, adj[v][w]));
      }
  }
}

int main(void){
  int m, i, j, h, k, inst = 1, flag = 1;

  while(scanf("%d %d", &n, &m), n != 0 || m !=0){
    for(int i = 0; i < MAX; i++)
      for(int j = 0; j < MAX; j++) adj[i][j] = MINF;
    while(m--){
      scanf("%d %d %d", &i, &j, &h); i--; j--;
      adj[i][j] = adj[j][i] = h;
    }

    // for(int i = 0; i < n; i++){
    //   for(int j = 0; j < n; j++)
    //     printf("%d ", adj[i][j] == MINF ? 0 : adj[i][j]);
    //   printf("\n");
    // }

    scanf("%d", &k);
    printf("Instancia %d\n", inst++);
    while(k--){
      //printf("COMECOU\n");
      for(int i = 0; i < n; i++){
        high[i] = MINF;
        vis[i] = 0;
      }
      scanf("%d %d", &i, &j); i--; j--;
      if(i == j) printf("0\n");
      else{
        dijkstra(i);
        printf("%d\n", high[j]);
      }
    }
    printf("\n");
  }
  return 0;
}
