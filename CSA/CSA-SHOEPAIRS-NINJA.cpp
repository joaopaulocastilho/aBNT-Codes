#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 112

int main(void){
  int i, ans, n, num, l[MAX], r[MAX];
  char f;
  
  memset(l, 0, sizeof(l));
  memset(r, 0, sizeof(r));
  scanf("%d ", &n);
  for(i = 0; i < n; i++){
    scanf("%d %c ", &num, &f);
    if(f == 'L') l[num]++;
    else r[num]++;
  }
  for(ans = i = 0; i < MAX; i++)
    ans += min(l[i], r[i]);
  printf("%d\n", ans);
  
  return 0;
}
