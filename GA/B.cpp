#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 112345

int maiors(char str[], int t) {
  int ret = 0, flag = 0, atual = 0, i;
  for (i = 0; i < t; i++) {
    ret = max(ret, atual);
    if (!flag) atual = 0;
    if (str[i] == '0') {
      flag = 1; atual++;
    } else {
      flag = 0; atual = 0;
    }
  }
  return ret;
}

int ini(char str[], int fim) {
  int ret = 0, i;
  for (i = 0; i < fim; i++) {
    if (str[i] == '0') ret++;
    else break;
  }
  return ret;
}

int fim(char str[], int f) {
  int ret = 0, i;
  for (i = f - 1; i >= 0; i--) {
    if (str[i] == '0') ret++;
    else break;
  }
  return ret;
}

int eh_tudo0(char str[], int t) {
  int i;
  for (i = 0; i < t; i++)
    if (str[i] != '0') return 0;
  return 1;
}

int main(void) {
  int n, k;
  long long resp;
  char str[MAX];
  scanf("%d %d ", &n, &k);
  scanf("%s", str);
  if (eh_tudo0(str, n)) {
    resp = (long long)n * k;
  } else if (k == 1) resp = maiors(str, n);
  else resp = max(maiors(str, n), ini(str, n) + fim(str, n));
  printf("%lld\n", resp);
  return 0;
}
