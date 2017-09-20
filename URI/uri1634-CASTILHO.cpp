#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 112345

int divisores[MAX];

int insere(int num){
  int raiz, i, indice=0;
  memset(divisores, 0, sizeof(divisores));
  raiz = sqrt(num);
  for(i=2; i<=raiz; i++){
    if(num%i == 0){
      divisores[indice++] = i;
      while(num%i == 0){
	num /= i;
      }
    }
  }
  if(num>1) divisores[indice++] = num;
  return indice;
}

void simp(int &a, int &b, int i){
  int j;
  for(j=0; j<i; j++){
    while(a%divisores[j] == 0 && b%divisores[j] == 0){
      a /= divisores[j];
      b /= divisores[j];
    }
  }
}

int main(void){
  int m, n, i, j, soma, a, b, bi[50000], tdiv;
  scanf("%d%d", &n, &m);
  while(n && m){
    soma = 0;
    for(i=0; i<n; i++){
      for(j=0; j<m; j++){
	scanf("%d", &bi[i]);
	if(j==m-1) soma += bi[i];
      }
    }
    tdiv = insere(soma);
    for(i=0; i<n; i++){
      a = bi[i];
      b = soma;
      simp(a, b, tdiv);
      printf("%d / %d\n", a, b);
    }
    scanf("%d%d", &n, &m);
  }
  return 0;
}
