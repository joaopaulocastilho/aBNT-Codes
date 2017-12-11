#include <stdio.h>
#include <algorithm>

using namespace std;

#define INF 112345678
#define MAX 1123

int main(void){
  int i, j, n, t, mine = INF, mini = -1, maxe1, maxe2, cure1, cure2;
  int trilha[MAX];
  
  scanf("%d", &t);
  for(i = 1; i <= t; i++){
    scanf("%d", &n);
    for(j = 0; j < n; j++) scanf("%d", &trilha[j]);
    maxe1 = maxe2 = 0;
    for(j = 0; j < n-1; j++){
      cure1 = trilha[j+1] - trilha[j];
      cure2 = trilha[j] - trilha[j+1];
      if(cure1 < 0) cure1 = 0;
      if(cure2 < 0) cure2 = 0;
      maxe1 += cure1;
      maxe2 += cure2;
    }
    // printf("%d %d\n", maxe1, maxe2);
    if(maxe1 < mine || maxe2 < mine){ mine = min(maxe1, maxe2); mini = i;}
  }
  printf("%d\n", mini);
  
  return 0;
}
