#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int upper = 0, i, end;
  char str[MAX];

  scanf("%s", str);
  end = strlen(str);
  for(i = 0; i < end; i++)
    if(str[i] <= 'Z') upper++;
  //printf("%d\n", upper);
  if(upper == end || (upper == end-1 && str[0] > 'Z')){
    for(i = 0; i < end; i++){
      if(i == 0 && str[i] > 'Z') printf("%c", str[i] - ' ');
      else if(str[i] <= 'Z') printf("%c", str[i] + ' ');
    }
    printf("\n");
  }
  else printf("%s\n", str);
}
