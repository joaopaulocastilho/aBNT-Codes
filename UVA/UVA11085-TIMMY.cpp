#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAX 11

int v[MAX], row[MAX], ans = MAX;

bool place(int r, int c){
  for(int prev = 0; prev < c; prev++)
    if(row[prev] == r || abs(row[prev]-r) == abs(prev - c))
      return false;
  return true;
}

void backtrack(int c){
  int count;
  if(c == 8){
    count = 0;
    for(int i = 0; i < 8; i++){
      //printf("(%d %d) ", row[i], v[i]);
      if(row[i] != v[i]) count++;
    }
    ans = min(ans, count);
    //printf("= %d\n", count);
  }
  for(int r = 0; r < 8; r++)
    if(place(r, c)){
      row[c] = r; backtrack(c+1);
    }
}

int main(void){
  int c=1;
  while(scanf("%d", &v[0]) != EOF){
    v[0]--;
    for(int i = 1; i < 8; i++){ scanf("%d", &v[i]); v[i]--; }
    memset(row, 0, sizeof(row));
    ans = 9;
    backtrack(0);
    printf("Case %d: %d\n", c++, ans);
  }
  return 0;
}
