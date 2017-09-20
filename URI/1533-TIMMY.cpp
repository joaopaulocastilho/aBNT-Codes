#include <stdio.h>


int main(void){
  int n, v, max, smax, p = 0, i, sp, pmax = 0;

  scanf("%d", &n);
  while(n){
    max = 0;
    smax = 0;
    for(i = 0; i < n; i++){
      scanf("%d", &v);
      if(v > max){
	smax = max;
	max = v;
	p = pmax;
	pmax = i+1;
	
      }
      else if(v < max && v > smax){
        smax = v;
	p = i+1;
      }
    }
    printf("%d\n", p);
    scanf("%d", &n);
  }



  return 0;
}
