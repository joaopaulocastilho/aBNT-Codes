#include <stdio.h>

#define MAX 1123

int main(void){
  char str[MAX];

  scanf("%s", str);
  if(str[0] >= 'a' && str[0] <= 'z') str[0] -= 32;
  printf("%s\n", str);
}
