#include <stdio.h>
#define MAX 1123

int main(void){
  int n, s, b, a;
  double ts, tb, ta, ss, sb, sa;
  char whatever[MAX];

  ts = tb = ta = ss = sb = sa = 0;
  scanf("%d\n", &n);
  while(n--){
    fgets(whatever, MAX, stdin);
    scanf("%d %d %d\n", &s, &b, &a);
    ts += s; tb += b; ta += a;
    scanf("%d %d %d\n", &s, &b, &a);
    ss += s; sb += b; sa += a;
  }

  printf("Pontos de Saque: %.2lf %%.\n", (100 * ss)/ts);
  printf("Pontos de Bloqueio: %.2lf %%.\n", (100 * sb)/tb);
  printf("Pontos de Ataque: %.2lf %%.\n", (100 * sa)/ta);
  return 0;
}
