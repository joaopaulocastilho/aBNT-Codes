#include <stdio.h>

#define MAX 112

int main(void){
  int n, i, v[MAX];

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for(i = 0; i < n; i++)
    if(i == 0) printf("%d\n", v[1] + v[0]);
    else if(i == n-1) printf("%d\n", v[n-2] + v[n-1]);
    else printf("%d\n", v[i-1] + v[i+1] + v[i]);
  
  return 0;
}
