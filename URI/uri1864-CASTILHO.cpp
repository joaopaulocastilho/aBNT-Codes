#include <stdio.h>

int main(void){
  int n;
  char str[] = {"LIFE IS NOT A PROBLEM TO BE SOLVED"};
  scanf("%d", &n);
  str[n] = '\0';
  printf("%s\n", str);
  return 0;
}
