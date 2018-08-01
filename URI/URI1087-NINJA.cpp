#include <bits/stdc++.h>

int main(void){
  int i1, i2, j1, j2;

  while(scanf("%d %d %d %d", &i1, &j1, &i2, &j2), i1){
    if(i1 == i2 && j1 == j2 ) printf("0\n");
    else if(i1 == i2 || j1 == j2 || abs(i1-i2) == abs(j1-j2)) printf("1\n");
    else printf("2\n");
  }

  return 0;
}
