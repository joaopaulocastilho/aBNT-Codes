#include <bits/stdc++.h>

using namespace std;

typedef struct{
  int palco;
  int inicio;
  int fim;
  int qtd;
} show_t;

const int MAXV = 1123;
const int MAXP = 1123;
const int INF = 1123456789;
 
int n, memo[MAXV][MAXP];
int to[MAXV];
vector<show_t> shows;

bool comp(show_t i, show_t j){
  return i.inicio < j.inicio;
}

int pd(int i, int bm){
  int next;
  if(i >= (int)shows.size() || i == -1){
    if(bm == (1<<n)-1) return 0;
    return -INF;
  }
  if(memo[i][bm] != -1) return memo[i][bm];
  
  memo[i][bm] = max(pd(to[i], bm|(1<<shows[i].palco))+shows[i].qtd, pd(i+1, bm));
  return memo[i][bm];
}

int main(void){
  vector<int> compress;
  map<int, int> mp;
  memset(memo, -1, sizeof(memo));
  cin >> n;
  for(int i = 0; i < n; i++){
    int s;
    cin >> s;
    while(s--){
      show_t show;
      cin >> show.inicio >> show.fim >> show.qtd;
      show.palco = i;
      shows.push_back(show);
      compress.push_back(show.inicio);
      compress.push_back(show.fim);     
    }
  }
  
  int count = 0;
  sort(compress.begin(), compress.end());
  for(int i = 0; i < (int)compress.size(); i++)
    if(mp.find(compress[i]) == mp.end()) mp[compress[i]] = count++;
  for(int i = 0; i < (int)shows.size(); i++){
    shows[i].inicio = mp[shows[i].inicio];
    shows[i].fim = mp[shows[i].fim];
  }

  sort(shows.begin(), shows.end(), comp);

  memset(to, -1, sizeof(to));
  for(int i = 0; i < (int)shows.size(); i++){
    for(int j = 0; j < (int)shows.size(); j++){
      if(shows[j].inicio >= shows[i].fim){
	to[i] = j;
	//cout << i << "->" << j << "\n";
	break;
      }
    }
  }
  int ans = -1;
  ans = pd(0, 0);
  ans = ans < 0 ? -1 : ans;
  cout << ans << "\n";
  return 0;
}
