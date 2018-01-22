#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int t, n, i, ans;
  char str[MAX], str2[MAX];

  scanf("%d", &t);
  while(t--){
    scanf("%d ", &n);
    scanf("%s ", str);
    for(ans = i = 1; i < n; i++){
      scanf("%s ", str2);
      if(strcmp(str2, str)) ans = 0;
    }
    printf("%s\n", ans ? str : "ingles");
  }
  
  return 0;
}
