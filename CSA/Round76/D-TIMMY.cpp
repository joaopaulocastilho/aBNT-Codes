#include <cstdio>
#include <set>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int > ii;

int valido(int i){
  return (i >= 1);
}

int main(void){
  int tc, i, j;
  ii aux;
  set<ii> s;
  queue<ii> q;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d %d", &i, &j);
    s.insert(ii(i, j));
    if(valido(i-1) && (s.find(ii(i-1, j-1)) == s.end())){
      q.push(ii(i-1, j-1));
    }
    if(valido(i-1) && (s.find(ii(i-1, j)) == s.end())){
      q.push(ii(i-1, j));
    }
    if(valido(i-1) && (s.find(ii(i-1, j+1)) == s.end())){
      q.push(ii(i-1, j+1));
    }
  }
  while(!q.empty()){
    aux = q.front();
    q.pop();
    s.insert(aux);
    if(valido((aux.first)-1) && (s.find(ii(aux.first-1, (aux.second)-1)) == s.end())){
      q.push(ii((aux.first)-1,  (aux.second)-1));
    }
    if(valido((aux.first)-1) && (s.find(ii(aux.first-1, (aux.second))) == s.end())){
      q.push(ii((aux.first)-1,  (aux.second)));
    }
    if(valido((aux.first)-1) && (s.find(ii(aux.first-1, (aux.second)+1)) == s.end())){
      q.push(ii((aux.first)-1,  (aux.second)+1));
    }
  }
  printf("%d\n", s.size());
    return 0;
}
