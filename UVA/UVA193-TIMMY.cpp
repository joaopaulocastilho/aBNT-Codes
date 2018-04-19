#include <cstdio>
#include <vector>

using namespace std;


#define GREY 0
#define BLACK 1
#define WHITE 2

vector<vector<int> > al;
vector<int> color;
vector<int> locans;
vector<int> ans;
int anscount, count, nodes, edges;

void bt(int idx){
  //printf("TAMO AI");
  vector<int> undo;
  color[idx] = BLACK;
  count++;
  for(int i = 0; i < (int)al[idx].size(); i++){
    if(color[al[idx][i]] == GREY){
      color[al[idx][i]] = WHITE;
      undo.push_back(al[idx][i]); 
    }
  }
  int called = 0;
  for(int i = 0; i < nodes; i++)
    if(color[i] == GREY){
      called = 1;
      bt(i);
    }
  if(!called && count > anscount){
    anscount = count;
    ans.clear();
    for(int i = 0;i < nodes; i++){
      if(color[i] == BLACK) ans.push_back(i);
    }
  }
  count--;
  color[idx] = GREY;
  for(int i = 0; i < (int)undo.size(); i++)
    color[undo[i]] = GREY;
}


int main(void){
  int tc, a, b;
  vector<int> aux;
  if(scanf("%d", &tc));
  while(tc--){
    color.clear(); al.clear(); aux.clear();
    anscount = count = 0;
    locans.clear(); ans.clear();
    if(scanf("%d %d", &nodes, &edges));
    for(int i = 0; i < nodes; i++){ color.push_back(GREY); al.push_back(aux); }
    for(int i = 0; i < edges; i++){
      if(scanf("%d %d", &a, &b));
      al[--a].push_back(--b);
      al[b].push_back(a);
    }
    for(int i = 0; i < nodes; i++){
      bt(i);
    }
    printf("%d\n", anscount);
    for(int i = 0; i < (int)ans.size(); i++){
      if(i) printf(" ");
      printf("%d", ans[i]+1);
    }
    printf("\n");
  }
  return 0;
}
