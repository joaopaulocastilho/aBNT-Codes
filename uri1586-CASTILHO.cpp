#include <stdio.h>
#include <string.h>
#define MAX 112345

typedef unsigned long long ull;

int pontos[MAX];
char nome[MAX][100];

void calcula_pontos(char nome[100], int indice){
  int i;
  for(i=0; nome[i] != 0; i++){
    pontos[indice] += nome[i];
  }
}

int verifica_empate(int tam){
  int inicio = 0, fim = tam-1;
  int i, meio, f;
  ull a=0, b=0;
  while(inicio <= fim){
    meio = (inicio+fim) / 2;
    a=b=f=0;
    for(i=meio; i>=0; i--){
      f++;
      a += (pontos[i]*f);
    }
    f=0;
    for(i=meio+1; i<tam; i++){
      f++;
      b += (pontos[i]*f);
   }
    if(a==b) return meio;
    if(a>b) fim = meio - 1;
    else inicio = meio + 1;
  }
  return -1;
}

int main(void){
  int n, i, sor;
  scanf("%d", &n);
  while(n){
    memset(pontos, 0, sizeof(pontos));
    for(i=0; i<n; i++){
      scanf("%s", nome[i]);
      calcula_pontos(nome[i], i);
    }
    sor = verifica_empate(n);
    if(sor==-1) printf("Impossibilidade de empate.\n");
    else printf("%s\n", nome[sor]);
    scanf("%d", &n);
  }
  return 0;
}
