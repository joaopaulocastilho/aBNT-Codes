#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
  int i, j, end, pal;
  char str[MAX], str1[MAX];
  
  while(fgets(str, MAX, stdin)){
    end = strlen(str);
    str[end-1] = 0;
    if(!strcmp(str, "DONE")) break;
    for(j = i = 0; i < end; i++){
      if(str[i] >= 'a' && str[i] <= 'z') str[i] -= ' ';
      if(str[i] >= 'A' && str[i] <= 'Z') str1[j++] = str[i];
    }
    for(pal = 1, i = 0, j--; i <= j; i++, j--)
      if(str1[i] != str1[j]) pal = 0;
    if(pal) printf("You won't be eaten!\n");
    else printf("Uh oh..\n");
  }



  return 0;
}
