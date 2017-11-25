#include <stdio.h>

using namespace std;

typedef long long ll;

#define MAX 112345

int main(void) {
  int n;
  ll re = 0, i, m1 = 0, m2 = 0, totalc = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &re);
    totalc += re;
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &re);
    if (re > m1) { m2 = m1; m1 = re; }
    else if (re > m2) {
      m2 = re;
    }
  }
  //printf("%d %d, %d", m1, m2, totalc);
  if (m1 + m2 >= totalc) printf("YES\n");
  else printf("NO\n");
  return 0;
}
