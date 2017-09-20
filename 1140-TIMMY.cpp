#include <stdio.h>

int main(void){
  char v[1050], l;
  int flag, i;
  while((v[0] = getchar()) != '*'){
    for(i = 1;v[i-1] != '\n'; i++)
      v[i] = getchar();
    l = v[0];
    i = 0;
    flag = 1;
    while(1){
      while((v[i] != ' ') && (v[i] != '\n')) i++;
      if(v[i] == '\n'){
	break;
      }
      else{
	i++;
	if(v[i] != l && v[i] != (l-32) && v[i] != (l+32)) flag = 0;
      }
    }
    if(flag) printf("Y\n");
    else printf("N\n");
  }
  return 0;
}
