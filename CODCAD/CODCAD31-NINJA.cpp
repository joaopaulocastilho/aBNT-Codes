#include <stdio.h>

#define MAX 1123456

int main(void){
  int n, i, ans;
  char str[MAX];

  scanf("%d ", &n);
  scanf("%s ", str); 
  for(ans = i = 0; i < n; i++){
    if(str[i] == 'P') ans += 2;
    else if(str[i] == 'C') ans += 2;
    else if(str[i] == 'A') ans++;
  }
  printf("%d\n", ans);
  
  return 0;
}
