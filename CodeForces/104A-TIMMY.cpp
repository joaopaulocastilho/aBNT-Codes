#include <cstdio>


int main(void){
  int n;
  scanf("%d", &n);
  if(n <= 10) printf("0\n");
  if(n == 11) printf("4\n");
  if(n > 11 && n <= 19) printf("4\n");
  if(n == 20) printf("15\n");
  if(n == 21) printf("4\n");
  if(n > 21) printf("0\n");  
  return 0;
}
