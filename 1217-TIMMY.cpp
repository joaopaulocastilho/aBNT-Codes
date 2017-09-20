#include <stdio.h>
#include <string.h>

int main(void){
  int nc, count, i;
  double c, cost = 0, fpd;
  char v[300];
  
  scanf("%d", &nc);
  for(i = 0; i < nc; i++){
    count = 1;
    scanf("%lf", &c);
    cost += c;
    while(scanf("%s", v) && (c = getchar()) != '\n') count++;
    fpd += (double)count;
    printf("day %d: %d kg\n", i+1, count);
  }
  printf("%.2lf kg by day\nR$ %.2lf by day\n", (fpd/nc), (cost/nc));
  return 0;
}
