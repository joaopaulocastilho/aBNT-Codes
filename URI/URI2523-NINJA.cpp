#include <stdio.h>

#define MAX 30

int main(void){
  int n, num;
  char alfa[MAX];

  while(scanf("%s\n", alfa) != EOF){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &num);
      printf("%c", alfa[num-1]);
    }
    printf("\n");
  }

  return 0;
}
