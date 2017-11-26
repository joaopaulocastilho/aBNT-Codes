#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  char str[MAX];
  int i, lc, uc;
  
  for(lc = uc = i = 0; (str[i] = getchar()) != '\n'; i++){
    if(str[i] >= 'a' && str[i] <= 'z') lc++;
    else uc++;
  }
  str[i] = '\0';
  for(i = 0; i < strlen(str); i++){
    if(uc > lc && str[i] >= 'a' && str[i] <= 'z') str[i] -= ' ';
    else if(lc >= uc && str[i] >= 'A' && str[i] <= 'Z') str[i] += ' ';
  }
  printf("%s\n", str);
  
  return 0;
}
