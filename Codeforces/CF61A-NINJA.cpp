#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  char num1[MAX], num2[MAX];

  scanf("%s\n", num1);
  scanf("%s\n", num2);
  for(int i = 0; i < strlen(num1); i++) printf("%d", num1[i] != num2[i] ? 1 : 0);
  printf("\n");
  return 0;
}
