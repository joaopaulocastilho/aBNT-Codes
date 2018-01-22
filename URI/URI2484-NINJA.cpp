#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, spaces, strl;
  char str[MAX];

  while(scanf("%s ", str) != EOF){
    spaces = 0;
    strl = strlen(str);
    while(strl){
      for(i = 0; i < spaces; i++) printf(" ");
      for(i = 0; i < strl; i++) printf("%s%c", i ? " " : "", str[i]);
      printf("\n");
      str[--strl] = 0;
      spaces++;
    }
    printf("\n");
  }




  return 0;
}
