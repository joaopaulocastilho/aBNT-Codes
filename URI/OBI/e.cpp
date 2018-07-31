#include <stdio.h>
#include <string.h>

#define MAX 112345
#define P 1000000007

int eh_palindromo(char str[], int tam) {
  int i, j;
  for (i = 0, j = tam - 1; i <= j; i++, j--)
    if (str[i] != str[j] && str[i] != '*' && str[j] != '*') return 0;
  return 1;
}

int main(void) {
  int i, n, c, inf, sup, flag[MAX], fp;
  long long resp = 1;
  char str[MAX], mn;
  scanf("%d %d ", &n, &c);
  scanf("%s", str);
  memset(flag, 0, sizeof(flag));
  if (!eh_palindromo(str, n)) { printf("0\n"); return 0; }
  for (i = 0; i < c; i++) {
    scanf("%d %d", &inf, &sup); inf--; sup--;
    fp = 0;
    if (str[inf] == '*' && str[sup] == '*' &&
        str[(n - 1) - inf] == '*' && str[(n - 1) - sup] == '*' &&
        !flag[sup] && !flag[inf] && !flag[(n - 1) - sup] && !flag[(n - 1) - inf]) {
      resp = ((resp * 26) % P) % P;
      fp = 1;
    } else if (str[inf] == '*' && str[(n-1) - inf] != '*' &&
               str[(n-1) - inf] != str[sup]) { printf("0\n"); return 0; }
    else if (str[sup] == '*' && str[(n-1) - sup] != '*' &&
             str[(n-1) - sup] != str[inf]) { printf("0\n"); return 0; }
    else if (str[inf] == '*' && str[sup] == '*' &&
             str[(n - 1) - inf] != str[(n - 1) - sup]) { printf("0\n"); return 0; }
    else if (str[inf] != str[sup] && str[inf] != '*' && str[sup] != '*')
      { printf("0\n"); return 0; }
    if (!fp) {
      mn = '*';
      if (str[sup] != '*') mn = str[sup];
      else if (str[inf] != '*') mn = str[inf];
      else if (str[(n - 1) - inf] != '*') mn = str[(n - 1) - inf];
      else if (str[(n - 1) - sup] != '*') mn = str[(n - 1) - sup];
      str[inf] = str[sup] = str[(n - 1) - inf] = str[(n - 1) - sup] = mn;
    }
    flag[inf] = flag[sup] = 1;
    flag[(n-1) - inf] = flag[(n-1) - sup] = 1;
  }
  printf("%d\n", resp % P);
  return 0;
}
