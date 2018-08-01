#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int end, i, d, flag;
  char str[MAX];

  while(scanf("%d %s ", &d, str), d){
    char c = d + '0';
    end = strlen(str);
    for(flag = 1, i = 0; i < end; i++){
      if(flag && str[i] != '0' && str[i] != c) flag = 0;
      if(!flag && str[i] != c) printf("%c", str[i]);
    }
    if(flag) printf("0");
    printf("\n");
  }
  
  return 0;
}
