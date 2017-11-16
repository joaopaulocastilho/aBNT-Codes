#include <stdio.h>
#include <string.h>

#define MAX 11234

int main(void){
  int i, n, t;
  char queue[MAX];

  scanf("%d %d\n", &n, &t);
  scanf("%s", queue);
  while(t--)
    for(i = 0; i < strlen(queue)-1; i++){
      if(queue[i+1] == 'G' && queue[i] == 'B'){
	queue[i+1] = 'B';
	queue[i] = 'G';
	i++;
      }
    }
  printf("%s\n", queue);
  return 0;
}
