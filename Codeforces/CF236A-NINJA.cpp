#include <stdio.h>
#include <string.h>

#define MAX 300

int main(void){
  char c, diff = 0;
  int letters[MAX];
  
  memset(letters, 0, sizeof(letters));
  while(scanf("%c", &c), c != '\n'){
    if(!letters[c]) diff++;
    letters[c]++;
  }
  printf("%s\n", diff % 2 ? "IGNORE HIM!" : "CHAT WITH HER!");
  
  return 0;
}
