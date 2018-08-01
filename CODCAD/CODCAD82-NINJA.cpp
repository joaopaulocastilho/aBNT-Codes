#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX 1123

typedef struct{
  int carac, desc;
}frase_t;

int c, f, n, d, memo[MAX][MAX];
frase_t frases[MAX];

int pd(int i, int chara){
  if(i == f) return 0;
  if(memo[i][chara] != -1) return memo[i][chara];
  if(chara + frases[i].carac > c) return memo[i][chara] = pd(i+1, chara);
  return memo[i][chara] = max(pd(i+1, chara), pd(i+1, chara+frases[i].carac) + frases[i].desc); 
}

int main(void){
  int i, caso = 1;
  
  while(scanf("%d %d", &c, &f), c){
    memset(memo, -1, sizeof(memo));
    for(i = 0; i < f; i++)
      scanf("%d %d", &frases[i].carac, &frases[i].desc);
    printf("Teste %d\n", caso++);
    printf("%d\n\n", pd(0, 0));
  }

  return 0;
}
