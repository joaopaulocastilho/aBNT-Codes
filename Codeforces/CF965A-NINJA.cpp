#include <bits/stdc++.h>

int main(void){
  int k, n, s, p, pagesEach;

  scanf("%d %d %d %d", &k, &n, &s, &p);
  pagesEach = ceil((double)n/s);
  printf("%d\n", (int)ceil((double)(pagesEach*k)/p));
  
  return 0;
}
