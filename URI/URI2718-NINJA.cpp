#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 1123

typedef long long int llu;

int main(void){
  int i, t, bigg, curr, bin[MAX];
  llu n, pot;
  
  scanf("%d", &t);
  while(t--){
    memset(bin, 0, sizeof(bin));
    scanf("%lld", &n);
    for(i = 50; i >= 0; i--){
      pot = pow(2, i);
      if(pot <= n){
	bin[i] = 1;
	n -= pot;
      }
    }
    for(i = 50, bigg = -1, curr = 0; i >= 0; i--){
      //printf("%d", bin[i]);
      if(bin[i] == 0){
	bigg = max(bigg, curr);
	curr = 0;
      }
      else curr++;
    }
    //printf("\n");
    printf("%d\n", max(bigg, curr));
  }
  
  return 0;
}
