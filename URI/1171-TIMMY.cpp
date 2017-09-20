#include <stdio.h>
#include <string.h>

#define MAX 112345

int main(void){
  int x[MAX], i, a, n;
  memset(x,(int)0,sizeof(int)*MAX);
  scanf("%d", &n);
  while(n--){
    scanf("%d", &a);
    x[a]++;
  }
  for(i=0; i < MAX; i++){
    if(x[i] != 0){
      printf("%d aparece %d vez(es)\n", i, x[i]);
    }
  }
  return 0;
}
