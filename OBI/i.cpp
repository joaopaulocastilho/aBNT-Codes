#include <bits/stdc++.h>

using namespace std;

int extGcd (int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1; y = 0; return a;
  } else {
    int g = extGcd(b, a % b, y, x);
    y -= a / b * x; return g;
  }
}

void diophantine(int a, int b, int c, int &x, int &y) {
  int d = extGcd(a, b, x, y);
  x *= c / d; y *= c / d;
}

int main(void) {
  int l, d, x1, y1, x2, y2;
  scanf("%d %d", &l, &d);
  diophantine(l, d, -1, x1, y1);
  diophantine(l, d, 0, x2, y2);
  //printf("%d %d %d %d\n", , y1, x2, y2);
  if (l * x1 + d * y1 == -1 && l * x2 + d * y2 == 1)
    printf("%d\n", min(abs(x1) + abs(y1), abs(x2) + abs(y2)));
  else if (l * x1 + d * y1 == -1)
    printf("%d\n", abs(x1) + abs(y1));
  else if (l * x2 + d * y2 == 1)
    printf("%d\n", abs(x2) + abs(y2));
  else printf("IMPOSSIVEL\n");
  return 0;
}
