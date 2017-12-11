#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, dur, ndepre, di, mond, ans;
  double down, loan, carval, numdep, paym, depre[MAX];

  while(scanf("%d %lf %lf %d", &dur, &down, &loan, &ndepre), dur >= 0){
    memset(depre, 0, sizeof(depre));
    for(i = 0; i < ndepre; i++){
      scanf("%d %lf", &mond, &numdep);
      depre[mond] = numdep;
    }
    carval = loan + down; paym = loan / dur;
    ans = di = 0;
    carval -= carval * depre[di];
    for(i = 1; carval < loan && i <= dur; i++, ans++){
      //printf("MES %d, loan %lf, carval %lf\n", i, loan, carval);
      if(depre[i]) di = i;
      //printf("%lf\n", depre[i]);
      loan -= paym;
      carval -= (carval * depre[di]);
    }
    printf("%d month%s\n", ans, ans != 1 ? "s" : "");
  }

  return 0;
}
