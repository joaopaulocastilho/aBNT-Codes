#include <stdio.h>

int main(void){
  int n, a, b, c, x, y, z, flag;

  scanf("%d", &n);
  while(n--){
    scanf("%d %d %d", &a, &b, &c);
    for(flag = 0, x = -100; x <= 100 && !flag; x++)
      for(y = x+1; y <= 100 && !flag; y++)
	for(z = y+1; z <= 100 && !flag; z++){
	  if(x + y + z == a && x*y*z == b && x*x + y*y + z*z == c){
	    printf("%d %d %d\n", x, y, z);
	    flag = 1;
	  }
	}
    if(!flag) printf("No solution.\n");
  }

  return 0;
}
