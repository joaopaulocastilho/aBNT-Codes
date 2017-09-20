#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

#define MAX 312
#define INF 112345678

typedef pair<int,int> ii;

int n, m, c, k;
int am[MAX][MAX];

int dijkstra(int ag[MAX][MAX], int s, int t){
  int dist[MAX], vis[MAX];

  for(int i = 0; i < n; i++) { dist[i] = INF; vis[i] = 0; }
  dist[s] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> q;
  q.push(ii(dist[s], s));
  while(!q.empty()){
    int current = q.top().second;
    q.pop();
    if(vis[current]) continue;
    vis[current] = 1;
    for(int i = 0; i < n; i++)
      if(ag[current][i] != -1 && !vis[i] && dist[i] > dist[current] + ag[current][i]){
        dist[i] = dist[current] + ag[current][i];
        q.push(ii(dist[i], i));
      }
    if(current == t) return dist[t];
  }
  return dist[t];
}

int main(void){
  int u, v, w, ans, tmp;

  while(scanf("%d %d %d %d", &n, &m, &c, &k), n || m || c || k){
    memset(am, -1, sizeof(am));
    while(m--){
      scanf("%d %d %d", &u, &v, &w);
      am[u][v] = w;
      am[v][u] = w;
    }
    //printf("%d\n", ans);
    ans = INF;
    for(int i = 0; i < c-1; i++){
      tmp = dijkstra(am, k, i);
      // printf("%d %d\n", i, tmp);
      for(int j = i; j < c-1; j++) tmp += am[j][j+1];
      for(int j = 0; j < n; j++) am[i][j] = am[j][i] = -1;
      //printf("%d %d\n", i, tmp);
      ans = min(ans, tmp);
    }
    ans = min(ans, dijkstra(am, k, c - 1));
    printf("%d\n", ans);
  }
  return 0;
}
