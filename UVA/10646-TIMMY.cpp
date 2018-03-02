#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 112

typedef struct carta{
  int num;
  char naipe;
  int valor;
} carta;

int main(void){
  carta baralho[MAX], cartinha, mao[MAX];
  char valor, naipinho;
  int topo, tc, numero, y, j, count = 1;
  scanf("%d", &tc);
  while(tc--){
    y = 0;
    topo = 0;
    for(int i = 0; i < 52; i++){
      scanf(" %c%c", &valor, &naipinho);
      numero = valor - '0';
      cartinha.num = numero; cartinha.naipe = naipinho; cartinha.valor = min(numero, 10);
      baralho[topo++] = cartinha;
    }
    //for(int i = topo-1; i > 0;  i--)
    topo--;
    for(j = 0; topo > 26; topo--, j++){
      mao[j] = baralho[topo];
    }
    for(int i = 0; i < 3; i++){
      cartinha = baralho[topo--];
      y += cartinha.valor;
      topo -= 10-cartinha.valor;
    }
    for(int i = 24; i >= 0; i--){
      baralho[++topo] = mao[i];
    }
    printf("Case %d: %c%c\n", count++, baralho[y-1].num + '0', baralho[y-1].naipe);
  }
  return 0;
}
