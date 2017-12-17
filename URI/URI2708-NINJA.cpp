#include <stdio.h>
#include <string.h>

#define MAX 51

int main(void){
  char str[MAX];
  int jl = 0, pl = 0, num;
  
  while(scanf("%s ", str), strcmp(str, "ABEND")){
    scanf("%d", &num);
    if(!strcmp(str, "SALIDA")){ pl += num; jl++; }
    else { pl -= num; jl--; }
  }
  printf("%d\n%d\n", pl, jl);
  
  return 0;
}
