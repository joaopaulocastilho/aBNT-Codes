#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

#define PB push_back
#define INF 112345678
typedef map<pair<int, int>, int> mpti;
typedef map<int, pair<int, int> > mitp;


mpti pti; 
mitp itp;
vector<int> v;
vector<int> resposta;
int euc_dist(int s, int t){
  pair<int, int> target(itp[t]);
  pair<int, int> source(itp[s]);
  return abs(target.first - source.first) + abs(target.second - source.second);
}

int dist(int s, int t1, int t2, int t3, int t4, int t5){
  return min(euc_dist(s, t1), 
	     min(euc_dist(s, t2),
		 min(euc_dist(s, t3), 
		     min(euc_dist(s, t4), euc_dist(s, t5))))) * v[s];
}

int main(void){
  int tc, n, x, y, value, mini, ans;
  for(int i = 0, count = 0; i < 5; i++)
    for(int j = 0; j < 5; j++){
      pti[make_pair(i, j)] = count;
      itp[count++] = make_pair(i,j);
    }
  scanf("%d", &tc);
  while(tc--){
    v.clear();
    for(int i = 0; i < 25; i++)
      v.PB(0);
    scanf("%d", &n);
    while(n--){
      scanf("%d %d %d", &x, &y, &value);
      mpti::iterator num = pti.find(make_pair(x, y));
      v[(num->second)] = value;
    };
    mini = INF;
    for(int i = 0; i < 25-4; i++)
      for(int j = i+1; j < 25-3; j++)
	for(int k = j+1; k < 25-2; k++)
	  for(int l = k+1; l < 25-1; l++)
	    for(int m = l+1; m < 25; m++){
	      ans = 0;
	      for(int o = 0; o < 25; o++){
		if(v[o] == 0) continue;
		ans += dist(o, i, j, k, l, m);
	      }
	      if(ans < mini){
		mini = ans;
		resposta.clear(); resposta.PB(i); resposta.PB(j); resposta.PB(k); resposta.PB(l); resposta.PB(m);
	      }
	    }
    for(vector<int>::iterator it = resposta.begin(); it != resposta.end(); ++it){
      if(it != resposta.begin()) printf(" ");
      printf("%d", (*it));
    }
    printf("\n");
  }
  return 0;
}
