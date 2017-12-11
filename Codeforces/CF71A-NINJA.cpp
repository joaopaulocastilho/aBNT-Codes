#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int n;
  char str[MAX];

  scanf("%d ", &n);
  while(n--){
    scanf("%s ", str);
    if(strlen(str) > 10)
      printf("%c%d%c\n", str[0], (int)strlen(str) - 2, str[strlen(str) - 1]);
    else printf("%s\n", str);
  }

  return 0;
}
