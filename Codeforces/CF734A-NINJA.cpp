#include <stdio.h>
#include <string.h>

#define MAX 112345

int main(void){
  int n, i, d, a, end; 
  char line[MAX];
  
  scanf("%d ", &n);
  scanf("%s", line);
  end = strlen(line);
  for(i = a = d = 0; i < end; i++){
    if(line[i] == 'A') a++;
    else d++;
  }
  if(a > d) printf("Anton\n");
  else if(d > a) printf("Danik\n");
  else printf("Friendship\n");
    
  return 0;
}
