#include <stdio.h>
#include <string.h>

void f_desloca(char a[100], int des){
  int i=0, j;
  while(a[i] != '\0'){
    for(j=0; j<des; j++){
      a[i]--;
      if(a[i] == 'A'-1) a[i] = 'Z'; 
    }
    i++;
  }
}
int main(void){
  int n, desloca;
  char str[100];
  scanf("%d", &n);
  while(n--){
    memset(str, 0, sizeof(str));
    getchar();
    scanf("%s", str);
    scanf("%d", &desloca);
    f_desloca(str, desloca);
    printf("%s\n", str);
  }
  return 0;
}
