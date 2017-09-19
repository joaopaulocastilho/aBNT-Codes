#include <stdio.h>
#include <string.h>

int f_fat(int n){
  if(n==1) return 1;
  if(n==0) return 1;
  return n*f_fat(n-1);
}

int main(void){
  int fat[6], i, flag=1, soma, j;
  char acm[20];
  for(i=1; i<=6; i++) fat[i] = f_fat(i);  
  while(flag){
    scanf("%s", acm);
    getchar();
    if(acm[0]-'0' == 0) return 0;
    for(i=0, j=strlen(acm), soma=0; acm[i] != '\0'; i++, j--)
      soma += (acm[i]-'0')*fat[j]; 
    printf("%d\n", soma);
  }
  return 0;
}
