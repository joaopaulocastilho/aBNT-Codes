#include <stdio.h>
#include <string.h>

#define MAX 1123
#define letra(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))

int main(void){
  int n, i, j, end, half;
  char str[MAX], ans[MAX];

  scanf("%d ", &n);
  while(n--){
    fgets(str, MAX, stdin);
    str[strlen(str)-1]  = 0;
    end = strlen(str);
    half = end/2;
    ans[end] = 0;
    for(i = 0, j = end-1; i < end; i++, j--){
      ans[j] = str[i];
      if(letra(ans[j])) ans[j] += 3; 
    }
    for(i = 0; i < end; i++)
      if(i >= half) ans[i]--;
    
    printf("%s\n", ans);
  }

  return 0;
}
