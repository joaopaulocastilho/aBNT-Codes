#include <stdio.h>



#define MAX 112



int main(void){
	
  int i, n, gifted, ans[MAX];


  
  scanf("%d", &n);

  for(i = 1; i <= n; i++){

    scanf("%d", &gifted);

    ans[gifted] = i;

  }

  for(i = 1; i <= n; i++)

    printf("%s%d", i == 1 ? "" : " ", ans[i]);


  return 0;
}