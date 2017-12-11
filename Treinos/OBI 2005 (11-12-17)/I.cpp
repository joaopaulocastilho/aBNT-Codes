#include <stdio.h>

#define MAX 112

int main(void) {
  int p, r, vivo[MAX], fila[MAX], i, j, qt, com, teste = 0, ac, count;
  while (scanf("%d %d", &p, &r), p) {
    teste++;
    for (i = 1; i <= p; i++) {
      vivo[i] = 1;
      scanf("%d", &fila[i]);
    }
    for (i = 0; i < r; i++) {
      scanf("%d %d", &qt, &com);
      for(count = 0, j = 1; count < qt; j++){
	if(!vivo[j]) continue;
	count++;
	scanf("%d", &ac);
	if(ac != com) vivo[j] = 0;
      }
    }
    for (i = 1; i <= p; i++) if (vivo[i]) printf("Teste %d\n%d\n\n", teste, fila[i]); 
  }
  return 0;
}
