#include <cstdio>

int main(void){
  int n, x, y, divx, divy;
  
  while(scanf("%d", &n), n){
    scanf("%d %d", &divx, &divy);
    while(n--){
      scanf("%d %d", &x, &y);
      if(x > divx)
	if(y > divy)
	  printf("NE\n");
	else if(y < divy)
	  printf("SE\n");
	else printf("divisa\n");
      else if(x < divx)
	if(y > divy)
	  printf("NO\n");
	else if(y < divy)
	  printf("SO\n");
	else printf("divisa\n");
      else printf("divisa\n");
    }
  }
  return 0;
}
