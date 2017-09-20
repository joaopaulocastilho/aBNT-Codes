#include <stdio.h>

int difa(int a){ if(a < 0) a *= -1; return a; }

int main(void){
  int n, t, l, i, s, pts[2], flag;
  scanf("%d%d%d", &n, &t, &l);
  pts[0]=pts[1]=0;
  flag=0;
  for(i=0; i<n; i++){
    scanf("%d", &s);
    if(difa(s-t) <= l){
      pts[flag] += difa(s-t);
      t = s;
    }
    if(flag) flag = 0;
    else flag = 1;
  }
  printf("%d %d\n", pts[0], pts[1]);
  return 0;
}
