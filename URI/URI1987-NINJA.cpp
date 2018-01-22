#include <stdio.h>

#define MAX 112

int main(void){
  int alg, sum, i;
  char num[MAX];

  while(scanf("%d %s ", &alg, num) != EOF){
    for(i = sum = 0; i < alg; i++){
      sum += num[i] - '0';
    }
    printf("%d %s\n", sum, sum % 3 ? "nao" : "sim");
  }

  return 0;
}
