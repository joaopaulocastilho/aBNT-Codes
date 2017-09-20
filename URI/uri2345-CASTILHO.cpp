#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main(void) {
  int a, b, c, d, t1, t2, menor = 112345678;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  t1 = a + b; t2 = c + d;
  menor = min(menor, abs(t1 - t2));
  t1 = a + c; t2 = b + d;
  menor = min(menor, abs(t1 - t2));
  t1 = a + d; t2 = b + c;
  menor = min(menor, abs(t1 - t2));
  printf("%d\n", menor);
  return 0;
}
