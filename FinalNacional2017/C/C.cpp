#include<stdio.h>
#include<string.h>

#define MAX 1123

int main(void) {
  int k, n, i, val, h[MAX], control = 1, qt;
  int vd, va, dim = 0, aum = 0;
  memset(h, 0, sizeof(h));
  scanf("%d %d", &k, &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &val);
    h[val]++;
  }
  if (n % k == 0) qt = n;
  else if ((n + 1) % k == 0) qt = n + 1;
  else if ((n - 1) % k == 0) qt = n - 1;
  else control = 0;
  for (i = 1; i <= k; i++) {
    if (h[i] > qt / k) {
      if (dim) control = 0;
      else {
        dim++;
        vd = i;
      }}
    if (h[i] < qt / k) {
      if (aum) control = 0;
      else {
        aum++;
        va = i;
      }}}
  if (control) {
    if (dim && aum) {
      if (h[vd] - h[va] == 2) printf("-%d +%d\n", vd, va);
      else printf("*\n");
    } else if (dim) {
      if (h[vd] - qt / k == 1) printf("-%d\n", vd);
      else printf("*\n");
    } else if (aum) {
      if (qt / k - h[va] == 1) printf("+%d\n", va);
      else printf("*\n");
    }
  } else printf("*\n");
  return 0;
}
