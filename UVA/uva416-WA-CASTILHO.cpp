#include <stdio.h>
#include <string.h>

#define MAX 15

int n, resp;
char conf[MAX][MAX];
char cola[MAX][MAX] = {{"1111110"},
			 {"0110000"},
			 {"1101101"},
			 {"1111001"},
			 {"0110011"},
			 {"1011011"},
			 {"1011111"},
			 {"1110000"},
			 {"1111111"},
			 {"1111011"}
};

int acendeu_depois(int led, int ind) {
  int i;
  for (i = ind; i < n; i++) if (conf[i][led]) return 1;
  return 0;
}

int pode(int ind, int num) {
  int j;
  for (j = 0; j < 7; j++) {
    if ((cola[num][j] == '0' && conf[ind][j] == 1) || (acendeu_depois(j, ind + 1) && conf[ind][j] == 0 && cola[num][j] == '1'))
      return 0;
  }
  return 1;
}

void bt(int ind, int num) {
  if (ind == n - 1) { resp = 1; return; }
  if (num == 0) return;
  if (pode(ind + 1, num - 1)) bt(ind + 1, num - 1);
}

int main(void) {
  int i, j;
  while (scanf("%d", &n), n) {
    memset(conf, 0, sizeof(conf));
    for (i = 0; i < n; i++) {
      scanf("%s ", conf[i]);
      for (j = 0; j < 7; j++) conf[i][j] = (conf[i][j] == 'Y');
    }
    for (resp = i = 0; i < 10; i++) if (pode(0, i)) bt(0, i);
    printf("%sMATCH\n", resp ? "" : "MIS");
  }
  return 0;
}
