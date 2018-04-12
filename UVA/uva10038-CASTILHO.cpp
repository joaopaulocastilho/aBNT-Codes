#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 3123

int main(void) {
  int n, i, resp, seq[MAX], flag[MAX];
  while (scanf("%d", &n) != EOF) {
    memset(flag, 0, sizeof(flag));
    for (i = 0; i < n; i++) scanf("%d", &seq[i]);
    for (i = 0; i < n - 1; i++) {
      if (abs(seq[i] - seq[i + 1]) >= n) continue;
      flag[abs(seq[i] - seq[i + 1])] = 1;
    }
    for (resp = i = 1; i < n; i++) resp &= flag[i];
    printf("%solly\n", resp ? "J" : "Not j");
  }
  return 0;
}
