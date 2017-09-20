#include <stdio.h>
#include <string.h>

#define MAX 30

typedef struct{ int aceito[MAX], tempo[MAX]; }problem_t;

int main(void){
  int N, temp, cont, soma, i;
  char np, sit[15];
  problem_t submit;
  while(scanf("%d", &N), N){
    memset(submit.aceito, 0, sizeof(submit.aceito));
    memset(submit.tempo, 0, sizeof(submit.tempo));
    cont=soma=0;
    for(i=0; i<N; i++){
      scanf("\n%c %d %s", &np, &temp, sit);
      if(sit[0] == 'i') submit.tempo[np-'A']+=20;
      else{
	submit.aceito[np-'A'] = 1;
	submit.tempo[np-'A'] += temp;
	cont++;
      }
    }
    for(i=0; i<='Z'-'A'; i++)
      if(submit.aceito[i]) soma+=submit.tempo[i];
    printf("%d %d\n", cont, soma);
  }
  return 0;
}
