#include <stdio.h>
#include <string.h>

#define upper(c) (c) >= 'A' && (c) <= 'Z'
#define MAX 112

int main(void){
  int i, ans;
  char str1[MAX], str2[MAX];

  scanf("%s ", str1);
  scanf("%s ", str2);

  for(i = 0; i < strlen(str1); i++){
    str1[i] += upper(str1[i]) ? ' ' : 0;
    str2[i] += upper(str2[i]) ? ' ' : 0;
  }

  //printf("%s %s\n", str1, str2);

  ans = strcmp(str1, str2);
  if(ans > 1) ans = 1;
  else if(ans < -1) ans = -1;
  printf("%d\n", ans);
  
  return 0;
}
