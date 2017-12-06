#include <cstdio>

int main(void){
  char c;
  while((c = getchar()) != EOF)
    if(c == 'H' || c == 'Q' || c == '9'){ printf("YES\n"); return 0; }
  printf("NO\n");  
  return 0;
}
