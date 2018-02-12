#include <stdio.h>

int main(void) {
  int d, m, resp, i;
  int mes[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 25 };
  while (scanf("%d %d", &m, &d) != EOF) {
    for (i = m; i <= 12; i++) {
      if (m == i) resp = mes[i] - d;
      else resp += mes[i];
    }
    if (resp == 1) printf("E vespera de natal!\n");
    else if (resp < 0) printf("Ja passou!\n");
    else if (!resp) printf("E natal!\n");
    else printf("Faltam %d dias para o natal!\n", resp);
  }
  return 0;
}
