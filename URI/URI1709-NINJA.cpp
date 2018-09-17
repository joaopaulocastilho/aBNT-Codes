#include <stdio.h>

#define MAX 212345

int main(void){
  int i, j, n, pos = 1, ans = 0, anda[MAX];

  scanf("%d", &n);

  for(j = i = 1; i <= n; i++){
    if(i <= n/2) anda[i] = j++;
    else anda[i] = j--;
    if(i == n/2) j = n/2;
    //printf("%d\n", anda[i]);
  }
  do{
    if(pos <= n/2) pos += anda[pos];
    else pos -= anda[pos];
    ans++;
  }while(pos != 1);

  printf("%d\n", ans);

  return 0;
}
