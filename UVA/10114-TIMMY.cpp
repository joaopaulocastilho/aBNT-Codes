#include <cstdio>
#include <cstring>

#define MAX 112

int main(void){
  double d, t, tax[MAX], value, down, payment;
  int n, pos, month, i, cur;
  while(scanf("%d %lf %lf %d", &n, &d, &t, &pos), n >= 0){
    payment = t / n;
    value = t;
    memset(tax, 0, sizeof(tax));
    while(pos--){
      scanf("%d %lf", &month, &down);
      tax[month] = down;
    }
    i = 0;
    cur = 0;
    value += d;
    value -= (value * tax[cur]);
    i++;
    while(value <= t){
      if(tax[i] != 0) cur = i;
      value -= (value * tax[cur]);
      t -= payment;
      i++;
    }
    printf("%d month%s\n", i-1, i-1 != 1 ? "s" : "");
  }
  return 0;
}
