#include <stdio.h>
#include <string.h>

int main(void) {
  int casos, i, flag, v[11], estao[7];
  scanf("%d", &casos);
  while (casos--) {
    memset(estao, 0, sizeof(estao));
    for (flag = 1, i = 0; i < 6; i++) {
      scanf("%d", &v[i]);
      if (v[i] < 1 || v[i] > 6) flag = 0;
      else estao[v[i]] = 1;
    }
    for (i = 1; i <= 6; i++) flag &= estao[i];
    flag &= (v[0] + v[5] == 7);
    flag &= (v[1] + v[3] == 7);
    flag &= (v[2] + v[4] == 7);
    printf("%s\n", flag ? "SIM" : "NAO");
  }
  return 0;
}
