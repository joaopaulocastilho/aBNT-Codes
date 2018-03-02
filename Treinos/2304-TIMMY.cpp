#include <cstdio>

int main(void){
  int qtd, n, i, valorinho, valor[4], pessoad, pessoad2;
  char acao, pessoa, pessoa2;
  scanf("%d %d", &qtd, &n);
  for(i = 1; i < 4; i++)
    valor[i] = qtd;
  while(n--){
    getchar();
    scanf("%c", &acao);
    if(acao == 'C'){
      getchar();
      scanf("%c", &pessoa);
      if(pessoa == 'D') pessoad = 1;
      if(pessoa == 'E') pessoad = 2;
      if(pessoa == 'F') pessoad = 3;
      scanf("%d", &valorinho);
      valor[pessoad] -= valorinho;
    }
    if(acao == 'V'){
      getchar();
      scanf("%c", &pessoa);
      if(pessoa == 'D') pessoad = 1;
      if(pessoa == 'E') pessoad = 2;
      if(pessoa == 'F') pessoad = 3;
      scanf("%d", &valorinho);
      valor[pessoad] += valorinho;
    }
    if(acao == 'A'){
      getchar();
      scanf("%c", &pessoa);
      if(pessoa == 'D') pessoad = 1;
      if(pessoa == 'E') pessoad = 2;
      if(pessoa == 'F') pessoad = 3;
      getchar();
      scanf("%c", &pessoa2);
      if(pessoa2 == 'D') pessoad2 = 1;
      if(pessoa2 == 'E') pessoad2 = 2;
      if(pessoa2 == 'F') pessoad2 = 3;
      scanf("%d", &valorinho);
      valor[pessoad2] -= valorinho;
      valor[pessoad] += valorinho;
    }
  }
  for(i = 1; i < 4; i++){
    if(i > 1) printf(" ");
    printf("%d", valor[i]);
  }
  printf("\n");
  return 0;
}
