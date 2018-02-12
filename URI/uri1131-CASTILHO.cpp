#include <stdio.h>

int main(void) {
  int g = 0, i = 0, emp = 0, ga, ia, op = 1, qtd = 0;
  while (op == 1) {
    scanf("%d %d", &ia, &ga);
    if (ia > ga) i++;
    else if (ia < ga) g++;
    else emp++;
    printf("Novo grenal (1-sim 2-nao)\n");
    scanf("%d", &op);
    qtd++;
  }
  printf("%d grenais\n", qtd);
  printf("Inter:%d\n", i);
  printf("Gremio:%d\n", g);
  printf("Empates:%d\n", emp);
  if (i == g) printf("Nao houve vencedor\n");
  else printf("%s venceu mais\n", (g > i) ? "Gremio" : "Inter");
  return 0;
}
