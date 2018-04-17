#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 112

int primes[MAX], n, use[MAX];

int is_prime(int n) {
  int i, raiz = sqrt(n);
  if (n == 1) return 0;
  if (n == 2) return 1;
  for (i = 2; i <= raiz; i++) if (n % i == 0) return 0;
  return 1;
}

void bt(int id, int v[]) {
  int i;
  if (id > n && primes[v[id - 1] + 1]) {
    for (i = 1; i <= n; i++) {
      if (i > 1) printf(" ");
      printf("%d", v[i]);
    }
    printf("\n");
    return;
  }
  for (i = 2; i <= n; i++) {
    if (!use[i] && primes[v[id - 1] + i]) {
      v[id] = i; use[i] = 1;
      bt(id + 1, v);
      use[i] = 0;
    }
  }
}

int main(void) {
  int i, circle[MAX], caso = 1;
  while (scanf("%d", &n) != EOF) {
    memset(use, 0, sizeof(use));
    if (caso > 1) printf("\n");
    printf("Case %d:\n", caso); caso++;
    for (i = 1; i < MAX; i++) primes[i] = is_prime(i);
    use[1] = 1; circle[1] = 1;
    bt(2, circle);
  }
  return 0;
}
