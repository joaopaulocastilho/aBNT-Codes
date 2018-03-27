#include <stdio.h>
#include <string.h>

#define MAX 212

int main(void){
  int i, first, end, inword;
  char line[MAX];

  scanf("%s", line);
  for(first = 1, end = strlen(line), inword = i = 0; i < end; i++){
    if(line[i] == 'W' && i + 2 < end && line[i+1] == 'U' && line[i+2] == 'B')
      {i += 2; inword = 0;}    
    else if(!inword){
      if(first) first = 0;
      else printf(" ");
      printf("%c", line[i]);
      inword = 1;
    }
    else printf("%c", line[i]);
  }
  printf("\n");
  
  return 0;
}
