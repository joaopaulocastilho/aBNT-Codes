#include <stdio.h>
#include <string.h>

#define MAX 15

int pert(char c, char str[]) {
  int i;
  for (i = 0; i < (int)strlen(str); i++)
    if (str[i] == c) return 1;
  return 0;
}

int main(void) {
  int n, coins[MAX], i, k;
  char l[MAX], r[MAX], dif[MAX];
  scanf("%d", &n);
  while (n--) {
    memset(coins, 0, sizeof(coins));
    for (k = 0; k < 3; k++) {
      scanf(" %s %s %s", l, r, dif);
      if (dif[0] == 'e')
        for (i = 0; i < (int)strlen(l); i++)
          coins[l[i] - 'A'] = coins[r[i] - 'A'] = 1;
      else {
        for (i = 0; i < 12; i++) {
          if (coins[i] == 1) continue;
          if (pert(i + 'A', l)) {
            if ((dif[0] == 'd' && coins[i] == 2) ||
                (dif[0] == 'u' && coins[i] == 3)) {
              coins[i] = 1;
              continue;
            }
            coins[i] = (dif[0] == 'd') ? 3 : 2;
          } else if (pert(i + 'A', r)) {
            if ((dif[0] == 'd' && coins[i] == 3) ||
                (dif[0] == 'u' && coins[i] == 2)) {
              coins[i] = 1;
              continue;
            }
            coins[i] = (dif[0] == 'd') ? 2 : 3;
          }
          else coins[i] = 1;
        }}}
    for (i = 0; i < 12; i++)
      if (coins[i] == 2 || coins[i] == 3)
        printf("%c is the counterfeit coin and it is %s.\n",
               i + 'A', coins[i] == 2 ? "heavy" : "light");
  }
  return 0;
}
