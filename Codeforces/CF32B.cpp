#include <stdio.h>
#include <string.h>

#define MAX 212

int main(void){
  int i;
  char str[MAX];
  
  scanf("%s ", str);
  for(i = 0; i < strlen(str); i++){
    if(str[i] == '-' && i < strlen(str)-1){
      if(str[i+1] == '-') printf("2");
      else printf("1");
      i++;
    }
    else printf("0");
  }
  printf("\n");
  
  return 0;
}
