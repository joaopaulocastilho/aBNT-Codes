#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAX = 11234;

typedef pair<int, int> ii;

vector<pair<ii, ii> > LA;

int dad[MAX], ra[MAX];

void Make(int x) { dad[x] = x; ra[x] = 0; }
int Find(int x) { return dad[x] == x ? x : (dad[x] = Find(dad[x])); }
int isSameSet(int i, int j) { return Find(i) == Find(j); }
void Union(int i, int j){
  int x, y;
  if(!isSameSet(i, j)){
    x = Find(i); y = Find(j);
    if(ra[x] > ra[y]) dad[y] = x;
    else{
      dad[x] = y;
      if(ra[x] == ra[y]) ra[y]++;
    }
  }
}

int kruskal(){
  int ans = 0;
  sort(LA.begin(), LA.end());
  for (auto [c, e] : LA) {
    auto [_, w] = c;
    auto [u, v] = e;
//  for(i = 0; i < (int)LA.size(); i++){
//    u = LA[i].second.first;
//    v = LA[i].second.second;
    if(!isSameSet(u, v)) ans += w;
    Union(u, v);
  }
  return ans;
}

int main(void){
  int i, n, f, r, a, b, w;

  memset(ra, 0, sizeof(ra));
  scanf("%d %d %d", &n, &f, &r);
  for(i = 0; i < f+r; i++) Make(i); 
  for(i = 0; i < f; i++){
    scanf("%d %d %d", &a, &b, &w); a--; b--;
    //LA.push_back(ii(ii(1, w), ii(a, b)));
    //LA.push_back({1, w, a, b});
    LA.push_back({{1, w},{a, b}});
  }
  for(i = 0; i < r; i++){
    scanf("%d %d %d", &a, &b, &w); a--; b--;
    //LA.push_back(ii(ii(2, w), ii(a, b)));
    LA.push_back({{2, w},{a, b}});
  }
  printf("%d\n", kruskal());
  
  return 0;
}
