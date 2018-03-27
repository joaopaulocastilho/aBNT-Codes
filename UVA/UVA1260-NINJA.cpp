#include <stdio.h>

#define MAX 1123

int main(void){
  int i, j, t, n, a[MAX], acum, ans;

  scanf("%d", &t);
  while(t--){
    scanf("%d", &n);
    for(ans = i = 0; i < n; i++) scanf("%d", &a[i]);
    for(i = 1; i < n; i++)
      for(j = 0; j < i; j++)
	if(a[j] <= a[i]) ans++;
    printf("%d\n", ans);
  }

  return 0;
}
