#include <stdio.h>
#include <string.h>

#define MAX 11

int main(void){
  int i, n;
  char ans[MAX], str[MAX];
  
  while(scanf("%d ", &n), n){
    strcpy(ans, "+x");
    for(i = 0; i < n-1; i++){
      scanf("%s ", str); 
      if(!strcmp(str, "+y")){
	if(!strcmp(ans, "+x")) strcpy(ans, "+y");
	else if(!strcmp(ans, "-x")) strcpy(ans, "-y");
	else if(!strcmp(ans, "+y")) strcpy(ans, "-x");
	else if(!strcmp(ans, "-y")) strcpy(ans, "+x");
      }
      else if(!strcmp(str, "-y")){
	if(!strcmp(ans, "+x")) strcpy(ans, "-y");
	else if(!strcmp(ans, "-x")) strcpy(ans, "+y");
	else if(!strcmp(ans, "+y")) strcpy(ans, "+x");
	else if(!strcmp(ans, "-y")) strcpy(ans, "-x");
      }
      else if(!strcmp(str, "+z")){
	if(!strcmp(ans, "+x")) strcpy(ans, "+z");
	else if(!strcmp(ans, "-x")) strcpy(ans, "-z");
	else if(!strcmp(ans, "+z")) strcpy(ans, "-x");
	else if(!strcmp(ans, "-z")) strcpy(ans, "+x");
      }
      else if(!strcmp(str, "-z")){
	if(!strcmp(ans, "+x")) strcpy(ans, "-z");
	else if(!strcmp(ans, "-x")) strcpy(ans, "+z");
	else if(!strcmp(ans, "+z")) strcpy(ans, "+x");
	else if(!strcmp(ans, "-z")) strcpy(ans, "-x");
      }
    }
    printf("%s\n", ans);
  }
  
  return 0;
}
