#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void){
  int caso = 1, end, i, j, ans, found;
  char str[MAX], tops[30];
  
  while(scanf("%s", str), strcmp(str, "end")){
    for(end = strlen(str),ans = i = 0; i < end; i++){
      for(found = j = 0; j < ans; j++)
	if(str[i] <= tops[j]){
	  found = 1;
	  tops[j] = str[i];
	  break;
	}
      if(!found) tops[ans++] = str[i];
    }
    printf("Case %d: %d\n", caso++, ans);
  }

  return 0;
}
