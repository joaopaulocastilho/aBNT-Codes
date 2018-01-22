#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, j, flag, t;
  char str1[MAX], str2[MAX];

  scanf("%d ", &t);
  while(t--){
    scanf("%s %s ", str1, str2);
    for(i = j = flag = 0; i < strlen(str1) || j < strlen(str2); ){
      if(!flag && i < strlen(str1)) printf("%c", str1[i++]);
      else if(flag && j < strlen(str2)) printf("%c", str2[j++]);
      flag ^= 1;
    }
    printf("\n");
  }
  
  return 0;
}
