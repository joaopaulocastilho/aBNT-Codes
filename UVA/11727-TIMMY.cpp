#include <cstdio>

int main(void){
  int n, a, b, c;
  
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    printf("Case %d: ", i);
    scanf("%d %d %d", &a, &b, &c);
    if(a > b)
      if(a > c)
	if(c > b)
	  printf("%d\n", c);
	else
	  printf("%d\n", b);
      else
	printf("%d\n", a);
    else
      if(b > c)
	if(c > a)
	  printf("%d\n", c);
	else
	  printf("%d\n", a);
      else
	printf("%d\n", b);
  }
  return 0;
}
