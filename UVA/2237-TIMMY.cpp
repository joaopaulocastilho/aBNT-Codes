#include <bits/stdc++.h>

using namespace std;

const int MAXV = 12321;
const int INF = 112345678;


int graph[MAXV][MAXV];
map<vector<int>, int > mp;
map<int, vector<int> > mpv;
vector<int> vs, vt;
vector<int> aux;
vector<int> ant;
int cont = 0;

void gera_vizinhos(vector<int> &v){
  aux = ant = v;
  for(int i = 0; i < 3; i++){
    swap(aux[i], aux[i+1]);
    if(mp.find(aux) == mp.end()){ mp[aux] = cont; mpv[cont++] = aux; }
    graph[mp[ant]][mp[aux]] = aux[i]+aux[i+1];
    swap(aux[i], aux[i+1]);
  }
  for(int i = 4; i < 7; i++){
    swap(aux[i], aux[i+1]);
    if(mp.find(aux) == mp.end()){ mp[aux] = cont; mpv[cont++] = aux; }
    graph[mp[ant]][mp[aux]] = aux[i]+aux[i+1];
    swap(aux[i], aux[i+1]);
  }
  for(int i = 0; i < 4; i++){
    swap(aux[i], aux[(i+4)%8]);
    if(mp.find(aux) == mp.end()){ mp[aux] = cont; mpv[cont++] = aux; }
    graph[mp[ant]][mp[aux]] = aux[i]+aux[(i+4)%8];
    swap(aux[i], aux[(i+4)%8]);
  }
}

int dijkstra(vector<int> &vs, vector<int> &vt){
  gera_vizinhos(vs);
  int dist[MAXV], vis[MAXV];

  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < MAXV; i++) dist[i] = INF;
  dist[mp[vs]] = 0;

  priority_queue< pair<int, vector<int> >, vector<pair<int, vector<int> > >, greater<pair<int, vector<int > > > > q;
  q.push(make_pair(dist[mp[vs]], vs));

  while(!q.empty()){
    pair<int, vector<int> > curr = q.top();
    q.pop();
    
    if(vis[mp[curr.second]]) continue;
    vis[mp[curr.second]] = 1;
    gera_vizinhos(curr.second);
    for(int i = 0; i < MAXV; i++){
      int v = i;
      int cost = graph[mp[curr.second]][v];
      if(cost == -1) continue;

      if(dist[mp[curr.second]]+cost < dist[v]) {
	dist[v] = dist[mp[curr.second]]+cost;
	q.push(make_pair(dist[v], mpv[v]));
      }
    }
  }
  return dist[mp[vt]];
}


int main(void){
  int num;
  ios::sync_with_stdio(false);

  memset(graph, -1, sizeof(graph));
  for(int i = 0; i < 8; i++){
    cin >> num;
    vs.push_back(num);
  }
  mp[vs] = cont++;
  for(int i = 0; i < 8; i++){
    cin >> num;
    vt.push_back(num);
  }
  mp[vs] = cont++;
  int ans = dijkstra(vs, vt);
  cout << ans << "\n";
  return 0;
}
