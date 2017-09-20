#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  char nome[MAX];
  int t;

  scanf("%d", &t);
  while(t--){
    scanf("%s\n", nome);
    if(strcmp(nome, "Batman") && strcmp(nome, "Batmain")) printf("Y\n");
    else printf("N\n");
  }

  return 0;
}
