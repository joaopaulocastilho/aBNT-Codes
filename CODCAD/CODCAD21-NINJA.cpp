#include <stdio.h>

int main(void){
  int n, a, b, ov = 0;
  char c;

  scanf("%d", &n);
  scanf("%d %c %d\n", &a, &c, &b);
  if(c == '+') ov = a + b > n;
  else ov = a * b > n;
  printf("%s\n", ov ? "OVERFLOW" : "OK");
  
  return 0;
}
