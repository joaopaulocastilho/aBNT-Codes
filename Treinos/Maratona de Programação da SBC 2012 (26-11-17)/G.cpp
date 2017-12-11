#include <stdio.h>
#include <algorithm>

#define MAX 112

using namespace std;

int main(void){
  int n, i, j, ans, grid1[MAX], grid2[MAX];

  while(scanf("%d", &n) != EOF){
    for(i = 0; i < n; i++) scanf("%d", &grid1[i]);
    for(i = 0; i < n; i++) scanf("%d", &grid2[i]);
    
    for(ans = i = 0; i < n; i++){
      for(j = i; grid2[i] != grid1[j] && j < n; j++);
      while(grid1[i] != grid2[i]) { swap(grid1[j], grid1[j--]); ans++; }
    }
    printf("%d\n", ans);
  }
  return 0;
}
