#include<stdio.h>
#include<string.h>

int escala[15][15], teclado[71];
int tons[] = {2, 2, 1, 2, 2, 2, 1};
char nota[5];

void mapeia(int nt) {
  memset(nota, 0, sizeof(nota));
  switch (nt) {
  case 0: strcpy(nota, "do"); break;
  case 1: strcpy(nota, "do#"); break;
  case 2: strcpy(nota, "re"); break;
  case 3: strcpy(nota, "re#"); break;
  case 4: strcpy(nota, "mi"); break;
  case 5: strcpy(nota, "fa"); break;
  case 6: strcpy(nota, "fa#"); break;
  case 7: strcpy(nota, "sol"); break;
  case 8: strcpy(nota, "sol#"); break;
  case 9: strcpy(nota, "la"); break;
  case 10: strcpy(nota, "la#"); break;
  case 11: strcpy(nota, "si"); break;
  }
}

void monta_escala() {
  int i, j, primeiro, desloc, pos;
  for (i = 0; i < 12; i++) {
    primeiro = i; desloc = 0;
    for (j = 0; j < 7; j++) {
      pos = (primeiro + desloc) % 12;
      escala[i][pos] = 1;
      desloc += tons[j];
    }}}

int main(void) {
  int n, i, j, nota_tec, flag[15], foi = 0;
  memset(escala, 0, sizeof(escala));
  for (i = 0; i < 12; i++) flag[i] = 1;
  scanf("%d", &n);
  monta_escala();
  for (i = 0; i < n; i++) {
    scanf("%d", &nota_tec);
    nota_tec--; nota_tec %= 12;
    for (j = 0; j < 12; j++) flag[j] &= escala[j][nota_tec];
  }
  for (i = 0; i < 12; i++)
    if (flag[i]) {
      foi = 1;
      mapeia(i);
      printf("%s\n", nota);
      break;
    }
  if (!foi) printf("desafinado\n");
  return 0;
}
