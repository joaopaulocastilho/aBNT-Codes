#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct{ int num[70], d[70], e[70]; }bota_t;

int main(void){
  int N, tam, i, cont;
  char lado;
  bota_t botas;
  while(scanf("%d", &N) != EOF){
    memset(botas.num, 0, sizeof(botas.num));
    memset(botas.d, 0, sizeof(botas.d));
    memset(botas.e, 0, sizeof(botas.e));
    cont=0;
    for(i=0; i<N; i++){
      getchar();
      scanf("%d %c", &tam, &lado);
      botas.num[tam]++;
      (lado=='D') ? botas.d[tam]++ : botas.e[tam]++;
    }
    for(i=30; i<=60; i++)
      if(botas.d[i] && botas.e[i]) cont+=min(botas.d[i], botas.e[i]);
    printf("%d\n", cont);
  }
  return 0;
}
