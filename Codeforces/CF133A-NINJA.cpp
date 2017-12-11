#include <stdio.h>

int main(void){
  int ans = 0;
  char c;

  while(scanf("%c", &c) != EOF)
    if(c == 'H' || c == 'Q' || c == '9') ans = 1;
  printf("%s\n", ans ? "YES" : "NO");
  
  return 0;
}
