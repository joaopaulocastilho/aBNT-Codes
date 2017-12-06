#include <cstdio>

int main(void){
  int count, j, n, numcount, reverso, flag;
  scanf("%d", &n);
  count = 0;
  for(int i = 0; i < n; i++){
    numcount = 0;
    reverso = 0;
    flag = 1;
    for(j = 0; j < (2 * n) - (2 * count); j++)
      printf(" ");
    for(j = 0; j <= 2 * count; j++){
      printf("%d", numcount);
      if(j != 2 * count) printf(" ");
      if(numcount == count && flag){
	reverso = 1;
	flag = 0;
      }
      numcount = numcount + (reverso ? -1 : 1);
    }
    count++;
    printf("\n");
  }
  numcount = 0;
  reverso = 0;
  flag = 1;
  count = n;
  for(int i = 0; i <= 2 * count; i++){
    printf("%d", numcount);
    if(i != 2 * count) printf(" ");
    if(numcount == count && flag){
      reverso = 1;
      flag = 0;
    }
    numcount = numcount + (reverso ? -1 : 1);
  }
  printf("\n");
  count = n-1;
  for(int i = 0; i < n; i++){
    numcount = 0;
    reverso = 0;
    flag = 1;
    for(j = 0; j < (2 * n) - (2 * count); j++)
      printf(" ");
    for(j = 0; j <= 2 * count; j++){
      printf("%d", numcount);
      if(j != 2 * count) printf(" ");
      if(numcount == count && flag){
	reverso = 1;
	flag = 0;
      }
      numcount = numcount + (reverso ? -1 : 1);
    }
    count--;
    printf("\n");
  }
  return 0;
}
