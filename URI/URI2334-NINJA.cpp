#include <stdio.h>

typedef unsigned long long ull;

int main(void){
  ull p;

  while(scanf("%llu", &p), p != (ull)-1){
    if(p == 0) printf("0\n");
    else printf("%llu\n", p-1);
  }

  return 0;
}
