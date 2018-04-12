#include <stdio.h>
#include <string.h>

#define MAX 1123

int pass[MAX], n;

int cheio() {
  int  i;
  for (i = 1; i <= n; i++)
    if (!pass[i]) return 0;
  return 1;
}

int main(void) {
  int m, c, resp = 0, i;
  memset(pass, 0, sizeof(pass));
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d", &c);
    pass[c]++;
    if (cheio()) {
      resp++;
      for (i = 1; i <= n; i++) pass[i]--;
      //for (i = 1; i <= n; i++) printf("%d ", pass[i]);
      //printf("\n");
    }
  }
  printf("%d\n", resp);
  return 0;
}
