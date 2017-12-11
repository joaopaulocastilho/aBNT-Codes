#include <stdio.h>
#include <string.h>

#define MAX 112

int main(void) {
  int n, l, c, i, tam, carac, linha, pag;
  char palavra[MAX];
  while (scanf("%d %d %d", &n, &l, &c) != EOF) {
    for (pag = linha = 1, carac = i = 0; i < n; i++) {
      scanf(" %s", palavra); tam = strlen(palavra);
      if (carac + tam <= c) { carac += (tam + 1); }
      else {
	carac = tam + 1;
	if (linha < l) { linha++; }
	else { linha = 1; pag++; }
      }
      // printf("Char == %d | Linha == %d | Pag  == %d | Palavla == %s\n", carac, linha, pag, palavra);	
    }
    printf("%d\n", pag);
  }
  return 0;
}
