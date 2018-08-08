#include <bits/stdc++.h>

int main(void){
  int p1[5], p2[5], i, ans;

  while(scanf("%d", &p1[0]) != EOF){
    for(i = 1; i < 5; i++) scanf("%d", &p1[i]);
    for(i = 0; i < 5; i++) scanf("%d", &p2[i]);
    for(ans = 1, i = 0; i < 5; i++) ans &= (p1[i] ^ p2[i]);
    printf("%s\n", ans ? "Y" : "N");
  }
  
  return 0;
}
