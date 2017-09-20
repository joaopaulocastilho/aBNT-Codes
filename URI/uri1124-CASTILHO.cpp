#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void){
  int L, C, R1, R2;
  while(scanf("%d%d%d%d", &L, &C, &R1, &R2), L && C && R1 && R2){
    if(max(R1*2, R2*2) <= min(L, C) && R1*2+R2*2 <= max(L, C)) printf("S\n");
    else printf("N\n");
  }
  return 0;
}
