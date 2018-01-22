#include <stdio.h>

#define MAX 1123

int main(void){
  int n, wh, th;
  char str[MAX];
  
  scanf("%d %d ", &n, &wh);
  while(n--){
    scanf("%s %d ", str, &th);
    if(th > wh) printf("%s\n", str);
  }

  return 0;
}
