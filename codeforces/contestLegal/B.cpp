#include <stdio.h>

typedef unsigned long long ull;

#define INF (ull)112345678901234567


ull max(ull a, ull b) {
  if (a > b) return a;
  return b;
}

ull min(ull a, ull b) {
  if (a < b) return a;
  return b;
}

int main(void) {
  int n, i;
  ull ts, tf, t, te = 0, nt, pos, pd, ant, aresp, resp;
  scanf("%llu %llu %llu %d", &ts, &tf, &t, &n);
  scanf("%llu", &nt);
  resp = max(0, ts - (nt - 1));
  pos = nt - 1;
  pd = ts + t; ant = nt;
  if (nt == 0) resp = INF;
  for (i = 1; i < n; i++) {
    scanf("%llu", &nt);
    if (nt - 1 == ant) {
      if (nt < ts) {
      pd += t;
    } else {
      if (pd <= nt) pd = nt + t;
      else pd += t;
    }

      continue;
    }
    te = max(0, pd - (nt - 1));
    aresp = resp;
    resp = min(resp, te);
    if (resp != aresp) pos = nt - 1;
    if (nt < ts) {
      pd += t;
    } else {
      if (pd <= nt) pd = nt + t;
      else pd += t;
    }
    ant = nt;
  }
  if (resp == INF) {
    pos = pd;
  }
  printf("%llu\n", pos);
  return 0;
}
