#include <stdio.h>
#include <string.h>

#define MAX 112
#define MAXN 15

int pts;

void mapeia(int v[], char c) {
  switch (c) {
  case 'A': v[0]++; pts += 4; break;
  case 'T': v[9]++; break;
  case 'J': v[10]++; pts++; break;
  case 'Q': v[11]++; pts +=2; break;
  case 'K': v[12]++; pts += 3; break;
  default: v[(c - '0') - 1]++; break;
  }
}

char maior(int q1, int q2, int q3, int q4) {
  if (q1 >= q2 && q1 >= q3 && q1 >= q4) return 'S';
  if (q2 > q1 && q2 >= q3 && q2 >= q4) return 'H';
  if (q3 > q1 && q3 > q2 && q3 >= q4) return 'D';
  return 'C';
}

int main(void) {
  int s[MAXN], h[MAXN], d[MAXN], c[MAXN], i;
  int qs, qh, qd, qc, ss, sh, sd, sc;
  char str[MAX];
  while (fgets(str, MAX, stdin)) {
    memset(s, 0, sizeof(s)); memset(h, 0, sizeof(s));
    memset(d, 0, sizeof(s)); memset(c, 0, sizeof(s));
    pts = qs = qh = qd = qc = ss = sh = sd = sc = 0;
    for (i = 0; i <= 36; i += 3) {
      switch (str[i + 1]) {
      case 'S': mapeia(s, str[i]); qs++; break;
      case 'H': mapeia(h, str[i]); qh++; break;
      case 'D': mapeia(d, str[i]); qd++; break;
      case 'C': mapeia(c, str[i]); qc++; break;
      }
    }
    if (s[0] || (s[12] && qs >= 2) || (s[11] && qs >= 3)) ss = 1;
    if (h[0] || (h[12] && qh >= 2) || (h[11] && qh >= 3)) sh = 1;
    if (d[0] || (d[12] && qd >= 2) || (d[11] && qd >= 3)) sd = 1;
    if (c[0] || (c[12] && qc >= 2) || (c[11] && qc >= 3)) sc = 1;
    if (s[12] && qs == 1) pts--;
    if (h[12] && qh == 1) pts--;
    if (d[12] && qd == 1) pts--;
    if (c[12] && qc == 1) pts--;
    if (s[11] && qs < 3) pts--;
    if (h[11] && qh < 3) pts--;
    if (d[11] && qd < 3) pts--;
    if (c[11] && qc < 3) pts--;
    if (s[10] && qs < 4) pts--;
    if (h[10] && qh < 4) pts--;
    if (d[10] && qd < 4) pts--;
    if (c[10] && qc < 4) pts--;
    if (pts >= 16 && ss && sh && sd && sc) printf("BID NO-TRUMP\n");
    else {
      if (qs == 2) pts++;
      else if (qs < 2) pts += 2;
      if (qh == 2) pts++;
      else if (qh < 2) pts += 2;
      if (qd == 2) pts++;
      else if (qd < 2) pts += 2;
      if (qc == 2) pts++;
      else if (qc < 2) pts += 2;
      if (pts >= 14)
        printf("BID %c\n", maior(qs, qh, qd, qc));
      else printf("PASS\n");
    }
  }
  return 0;
}
