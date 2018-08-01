#include <stdio.h>

int main(void){
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);
  
  if(a < b && a < c) printf("1\n");
  else if(b < a && b < c) printf("2\n");
  else if(c < b && c < a) printf("3\n");
  

  if((a < b && a > c) || (a < c && a > b)) printf("1\n");
  else if((b < a && b > c) || (b < c && b > a)) printf("2\n");  
  else if((c < b && c > a || c < a && c > b)) printf("3\n");  

  if(a > b && a > c) printf("1\n");
  else if(b > a && b > c) printf("2\n");
  else if(c > b && c > a) printf("3\n");
  
  return 0;
}
