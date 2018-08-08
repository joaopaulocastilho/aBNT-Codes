#include <bits/stdc++.h>

int main(void){
  int write, i, n, m, curr;

  scanf("%d %d", &n, &m);
  for(curr = i = 0; i < n; i++, curr = curr % m){
    scanf("%d", &write);
    curr += write;
    printf("%s%d", i ? " " : "", curr/m);
  }
  printf("\n");

  return 0;
}
