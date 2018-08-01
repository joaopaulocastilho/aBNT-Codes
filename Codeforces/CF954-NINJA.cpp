#include <stdio.h>

#define MAX 112

int main(void){
  int i, n, ans = 0;
  char str[MAX];

  scanf("%d ", &n);
  scanf("%s ", str);
  for(i = 0; i < n; i++){
    if((str[i] == 'U' && str[i+1] == 'R') || (str[i] == 'R' && str[i+1] == 'U'))
      {i++; ans++;}
  }
  printf("%d\n", n-ans);
  
  return 0;
}
