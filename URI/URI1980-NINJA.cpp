#include <stdio.h>
#include <string.h>

#define MAX 21

typedef long long int lli;

lli fat(int x){
  if(x == 0) return 1;
  return x * fat(x-1);
}

int main(void){
  char str[MAX];

  while(scanf("%s ", str), strcmp(str, "0")){
    printf("%lld\n", fat(strlen(str)));
  }

  return 0;
}
