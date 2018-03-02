#include <cstdio>
#include <cstring>

int main(void){
  int i = 0;
  char numero[10], num;
  while(scanf("%c", &num) != EOF)
    if(num >= '0' && num <= '9')
      numero[i++] = num;
  for(; i >= 0; i--)
    printf("%c", numero[i]);
  printf("\n");
  return 0;
}
