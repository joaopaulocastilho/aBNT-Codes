#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, j, end, flag;
  char num[MAX], ans[MAX], fail[2];

  while(scanf("%s %s ", fail, num), strcmp(fail, "0") || strcmp(num, "0")){
    end  = strlen(num);
    for(j = i = 0, flag = 1; i < strlen(num); i++){
      if(num[i] == fail[0]) continue;
      if(flag && num[i] == '0') continue;
      flag = 0;
      ans[j++] = num[i];
    }
    if(j == 0) ans[j++] = '0';
    ans[j] = 0;
    printf("%s\n", ans);
  }

  return 0;
}
