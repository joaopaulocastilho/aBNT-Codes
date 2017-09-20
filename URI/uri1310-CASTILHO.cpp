//ALGORITMO DE KADANE

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 51

int N, S[MAX][MAX], l[MAX];

int maxSubArraySum(){
  int max_so_far = l[0];
  int curr_max = l[0], i;
   for (i=1; i<N; i++){
        curr_max = max(l[i], curr_max+l[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}

int main(void){
  int c, i, val;
  while(scanf("%d", &N) != EOF){
    scanf("%d", &c);
    memset(S, -1, sizeof(S));
    for(i=0, val=0; i<N; i++){ scanf("%d", &l[i]); l[i]-=c; }
    val = max(0, maxSubArraySum());
    printf("%d\n", val);
  }
  return 0;
}
