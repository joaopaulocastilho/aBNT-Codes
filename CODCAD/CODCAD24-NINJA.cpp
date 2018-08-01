#include <stdio.h>

#define MAX 112345

int main(void){
  int n, i, v[MAX], ttl, sum;

  scanf("%d", &n);
  for(ttl = i = 0; i < n; i++){
    scanf("%d", &v[i]);
    ttl += v[i];
  }
  for(sum = i = 0; i < n; i++){
    sum += v[i];
    if(2 * sum == ttl){
      printf("%d\n", i+1);
      break;
    }
  }
  return 0;
}
