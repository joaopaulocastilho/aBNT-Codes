#include<stdio.h>

typedef long long ll;

int main(void) {
  ll fat[15];
  int i, n;
  fat[0] = 1;
  for (i = 1; i <= 13; i++) fat[i] = fat[i - 1] * i;
  scanf("%d", &n);
  printf("%lld\n", fat[n]);
  return 0;
}
