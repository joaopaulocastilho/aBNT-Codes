#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 2123456

int memo[MAX];

int main(void){
  int bloco[30];
  int tc, m, n;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= m; i++) memo[i] = i;
    for(int i = 0; i < n; i++)
      scanf("%d", &bloco[i]);
    for(int i = 0; i < n; i++){
      if(bloco[i] == 1) continue;
      memo[bloco[i]] = 1;
      for(int j = 1; j <= m; j++) memo[bloco[i]+j] = min(memo[bloco[i]+j], memo[j]+ 1);      
    }
    printf("%d\n", memo[m]);
  }
  return 0;
}
