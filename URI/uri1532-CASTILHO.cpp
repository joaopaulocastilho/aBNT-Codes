#include<stdio.h>

int main(void) {
  int n, v, i, flag, j, quique, andou;
  while (scanf("%d %d", &n, &v), n) {
    for (flag = 0, i = 1; i <= v; i++) {
      for (quique = i, andou = 0; quique; quique--) {
        for (j = quique; j > 0; j--) {
          andou += quique;
          if (andou == n) flag = 1;
        }
      }
    }
    printf("%spossivel\n", flag ? "" : "im");
  }
  return 0;
}
