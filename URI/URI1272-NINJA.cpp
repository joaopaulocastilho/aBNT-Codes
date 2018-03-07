#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void){
  int i, end, n;
  char line[MAX];

  scanf("%d ", &n); 
  while(n--){
    fgets(line, MAX, stdin);
    line[strlen(line)-1] = 0;
    end = strlen(line);
    //printf("%s\n", line);
    for(i = 0; i < end; i++){
      if(line[i] == ' ') continue;
      printf("%c", line[i]);
      while(line[i+1] != ' ' && i < end-1) i++;
    }
    printf("\n");
  }
  
  return 0;
}
