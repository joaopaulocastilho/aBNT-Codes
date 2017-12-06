#include <cstdio>
#include <cstdlib>

int main(void){
  int a = 0, x = 0, y = 0;
  for(int i = 0; i < 5 && !a; i++){
    for(int j = 0; j < 5; j++){
      scanf("%d", &a);
      if(a == 1){
	x = j; y = i;
	break;
      }
    }
  }
  printf("%d\n", abs(2 - x) + abs(2 - y ));
  return 0;
}
