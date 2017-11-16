#include <stdio.h>
#include <string.h>

#define MAX 1123

#define valido(x) (x) >= 0 && (x) <= 1000

int main(void){
  int i, j, p, q, l, r, a, b, ans = 0;
  int xon[MAX], zon[MAX];

  memset(xon, 0, sizeof(xon));
  memset(zon, 0, sizeof(zon));		
  scanf("%d %d %d %d", &p, &q, &l, &r);

  for(i = 0; i < p; i++){
    scanf("%d %d", &a, &b);
    for(j = a; j <= b; j++) xon[j] = 1;
  }
  for(i = 0; i < q; i++){
    scanf("%d %d", &a, &b);
    for(j = a; j <= b; j++) zon[j] = 1;
  }

  for(i = l; i <= r; i++)
    for(j = 0; j <= 1000; j++){
      if(zon[j] && valido(j+i) && xon[j+i]){
	ans++;
	break;
      }
    }

  printf("%d\n", ans);
  return 0;
}
