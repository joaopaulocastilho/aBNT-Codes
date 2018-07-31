#include <stdio.h>

#define TAB 8

int dicavalo[] = { -2, -1, -2, -1, 2, 1, 2, 1 };
int djcavalo[] = { 1, 2, -1, -2, 1, 2, -1, -2 };

int valido(int x, int y) {
  if (x >= 0 && x < TAB && y >= 0 && y < TAB) return 1;
  return 0;
}

int main(void) {
  char pic, pdc;
  int pin, pdn, li, ci, lf, cf, resp, i;
  scanf("%c%d %c%d", &pic, &pin, &pdc, &pdn);
  li = pic - 'a'; ci = pin - 1;
  lf = pdc - 'a'; cf = pdn - 1;
  for (resp = i = 0; !resp && i < 8; i++) {
    if (valido(li + dicavalo[i], ci + djcavalo[i]) &&
        li + dicavalo[i] == lf && ci + djcavalo[i] == cf) resp = 1;
  }
  printf("%sVALIDO\n", resp ? "" : "IN");
  return 0;
}
