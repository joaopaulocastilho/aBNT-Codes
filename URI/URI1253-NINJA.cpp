#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int t, shift, i, end;
  char str[MAX];

  scanf("%d ", &t);
  while(t--){
    scanf("%s ", str);
    scanf("%d ", &shift);
    end = strlen(str);
    for(i = 0; i < end; i++){
      str[i] -= shift;
      if(str[i] < 'A') str[i] += 26;
      printf("%c", str[i]);
    }
    printf("\n");
  }
  
  return 0;
}
