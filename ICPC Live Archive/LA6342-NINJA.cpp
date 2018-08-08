#include <bits/stdc++.h>

const int MAX = 12;

int main(void){
  int t, i, j, ans;
  char str[MAX];
  
  scanf("%d", &t);
  while(t--){
    scanf(" %s", str);
    for(ans = 1, i = 0, j = strlen(str)-1; i <= j; i++, j--)
      ans &= str[i] == str[j];
    printf("%s\n", ans ? "YES" : "NO");
  }

  return 0;
}
