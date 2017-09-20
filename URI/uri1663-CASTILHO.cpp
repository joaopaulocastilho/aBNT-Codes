#include <stdio.h>

#define MAX 112345

int main(void){
  int N, i, p[MAX], pi[MAX], flag;
  while(scanf("%d", &N), N){
    for(i=1; i<=N; i++) scanf("%d", &p[i]);
    for(i=1; i<=N; i++) pi[p[i]] = i;
    for(i=1, flag=1; flag && i<=N; i++)
      if(p[i]!=pi[i]) flag=0;
    printf("%sambiguous\n", flag ? "" : "not ");
  }
  return 0;
}
