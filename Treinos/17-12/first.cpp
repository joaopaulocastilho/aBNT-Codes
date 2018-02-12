#include <stdio.h>

using namespace std;

int dx[] = { -1, 0, 1, -1, -1, 1, -1, 1 };
int dy[] = { 0, -1, 0, 1, -1, 1, 1, -1 };

void movimenta(int &xa, int &ya, int m) {
  if (m == 1) ya++;
  else if (m == 2) ya--;
  else if (m == 3) xa++;
  else xa--;
}

int escuta(int xa, int ya, int x, int y) {
  if (xa >= x - 1 && xa <= x + 1 && ya >= y - 1 && ya <= y + 1)
    return 1;
  return 0;
}

int main(void) {
  int n, m, x, y, k, resp = 0, mov, xa = 0, ya = 0;
  scanf("%d %d", &n, &m);
  scanf("%d %d", &x, &y);
  scanf("%d", &k);
  if (escuta(xa, ya, x, y)) resp++;
  while (k--) {
    scanf("%d", &mov);
    printf("mov[%d] ", mov);
    movimenta(xa, ya, mov);
    if (escuta(xa, ya, x, y)) { resp++; printf("P "); }
      printf("%d %d %d %d\n", xa, ya, x, y);
  }
  printf("%d\n", resp);
  return 0;
}
