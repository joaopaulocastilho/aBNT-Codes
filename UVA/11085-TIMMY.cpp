#include <cstdio>
#include <cstring>


#define MAX 11

int v[MAX], row[MAX], ans = MAX;

bool place(int r, int c){
  for(int prev = 0; prev < c; prev++)
    if(row[prev] == r || abs(row[prev]-r) == abs(prev - c))
      return false;
  return true;
}

void backtrack(int c){
  int count = 0;
  if(c == 8){
    for(int i = 0; i < 8; i++) if(row[i] != v[i]) count++;
    ans = min(ans, count);
  }
  for(int r = 0; r < 8; r++)
    if(place(r, c))
      row[c] = r; backtrack(c+1);
}

int main(void){
  
  while(scanf("%d", &v[0]) != EOF){
    for(int i = 1; i < 8; i++) scanf("%d", &v[i]);
    memset(row, 0, sizeof(row)); lineCounter = 0;
    backtrack(0);
    printf("%d\n", ans);
  }
  return 0;
}
