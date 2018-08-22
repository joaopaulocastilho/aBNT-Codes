#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int, pair<int, char> > > vppiic;

const int INF = 112345678;
const int MAXV = 21234;

int dist[MAXV][200], vis[MAXV][200];


int dijkstra(int s, int t, vector<vector<pair<pair<int, int>, char> > > &dg){
  int i;
  memset(vis, 0, sizeof(vis));
  for(i = 0; i < MAXV; i++)
    for(int j = 0; j < 200; j++)
      dist[i][j] = INF;
  dist[s]['z'+1] = 0;
  priority_queue<pair<int, pair<int, char> >, vppiic, greater<pair<int, pair<int, char> > > > q;
  q.push(make_pair(dist[s]['z'+1], make_pair(s, 'z'+1)));
  
  while(!q.empty()){
    pair<int, pair<int, char> > current = q.top();
    q.pop();
    if(vis[current.second.first][current.second.second]) continue;
    vis[current.second.first][current.second.second] = 1;
    for(i = 0; i < (int)dg[current.second.first].size(); i++){
      int v = dg[current.second.first][i].first.second;
      int peso = dg[current.second.first][i].first.first;
      int came = dg[current.second.first][i].second;
      //cout << "Sou o " << current.second.first << ", meu vizinho é " << v << ", com peso " << peso << "\n";
      if(!vis[v][came] && dist[v][came] > dist[current.second.first][current.second.second] + peso && came != current.second.second){
	dist[v][came] = dist[current.second.first][current.second.second] + peso;
	q.push(make_pair(dist[v][came], make_pair(v, came)));
      }
    }
  }
  int ans = INF;
  for(int i = 0; i < 200; i++){
    ans = min(ans, dist[t][i]);
  }
  return ans;
}

int main(void){
  int n;
  while(cin >> n, n){
    vector<vector<pair<pair<int, int>, char> > > dg(21234);
    string s, t;
    map<string, int> mp;
    cin >> s >> t;
    int count = 0;
    mp[s] = count++;
    mp[t] = count++;
    for(int i = 0; i < n; i++){
      int peso;
      pair<int, int> pii;
      string l1, l2, p;
      cin >> l1 >> l2 >> p;
      if(mp.find(l1) == mp.end()){ mp[l1] = count++; }
      if(mp.find(l2) == mp.end()){ mp[l2] = count++; }
      peso = p.size();
      pii = make_pair(peso, mp[l2]);
      dg[mp[l1]].push_back(make_pair(pii, p[0]));
      pii = make_pair(peso, mp[l1]);
      dg[mp[l2]].push_back(make_pair(pii, p[0]));    
    }
    int ans = dijkstra(mp[s], mp[t], dg);
    if(ans == INF) cout << "impossivel";
    else cout << ans;
    cout << "\n";
  }
  return 0;
}
