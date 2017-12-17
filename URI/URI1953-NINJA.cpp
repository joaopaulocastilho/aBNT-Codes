#include <stdio.h>
#include <string.h>

#define MAX 11234

int main(void){
  int n, matr, epr, ehd, intr;
  char str[MAX];
  
  while(scanf("%d", &n) != EOF){
    epr = ehd = intr = 0;
    while(n--){
      scanf("%d %s ", &matr, str);
      if(!strcmp(str, "EPR")) epr++;
      else if(!strcmp(str, "EHD")) ehd++;
      else intr++;
    }
    printf("EPR: %d\n", epr);
    printf("EHD: %d\n", ehd);
    printf("INTRUSOS: %d\n", intr);
  }
  return 0;
}
