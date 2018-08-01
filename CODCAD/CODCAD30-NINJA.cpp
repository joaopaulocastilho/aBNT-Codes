#include <stdio.h>

#define MAX 11234

int main(void){
  int n, ans, i;
  char str1[MAX], str2[MAX];

  scanf("%d ", &n);
  scanf("%s %s ", str1, str2);

  for(ans = i = 0; i < n; i++)
    if(str1[i] == str2[i]) ans++;
  printf("%d\n", ans);
  
  return 0;
}
