#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, n;
  char str[MAX];

  scanf("%d ", &n);
  for(i = 0; i < n; i++){
    scanf("%s", str);
    if(i) printf(" ");
    if(strlen(str) == 3 && str[0] == 'U' && str[1] == 'R') printf("URI");
    else if(strlen(str) == 3 && str[0] == 'O' && str[1] == 'B') printf("OBI");
    else printf("%s", str);
  }
  printf("\n");
  return 0;
}
