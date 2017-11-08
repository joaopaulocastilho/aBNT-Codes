#include<stdio.h>
#include<string.h>

#define MAX 2123456
#define MAXP 3123456
#define LIM 2000001

int n, pla, ftA[MAX], ftB[MAX], A[MAXP], B[MAXP];

int rsq(int ft[], int i) {
  int ret;
  for (ret = 0; i > 0; i -= (i & -i)) ret += ft[i];
  return ret;
}

void update(int ft[], int i, int v) {
  for ( ; i <= LIM; i += (i & -i)) ft[i] += v;
}

int impedido(int time, int id) {
  int qtd;
  if (time) {
    qtd = rsq(ftA, B[id] - 1);
    if (qtd < ((n) / 11.)) return 1;
    return 0;
  }
  qtd = pla - rsq(ftB, A[id]);
  if (qtd < ((n) / 11.)) return 1;
  return 0;
}

int main(void) {
  int e, i, idp, newpos, pa, pb, golv;
  char op, time;
  while (scanf("%d %d", &n, &e), n) {
    memset(ftA, 0, sizeof(ftA)); memset(ftB, 0, sizeof(ftB));
    pa = pb = 0; golv = 1; pla = n >> 1;
    for (i = 0; i < pla; i++)
      { scanf("%d", &A[i]); A[i]++; update(ftA, A[i], 1); }
    for (i = 0; i < pla; i++)
      { scanf("%d", &B[i]); B[i]++; update(ftB, B[i], 1); }
    while (e--) {
      scanf(" %c", &op);
      switch (op) {
      case 'I':
      case 'P':
        scanf(" %c%d", &time, &idp);
        if (impedido((time == 'A') ? 0 : 1, idp)) golv = 0;
        break;
      case 'M':
        scanf(" %c%d %d", &time, &idp, &newpos); newpos++;
        update((time == 'A') ? ftA : ftB, (time == 'A') ? A[idp] : B[idp],
               -1);
        if (time == 'A') A[idp] = newpos;
        else B[idp] = newpos;
        update((time == 'A') ? ftA : ftB, (time == 'A') ? A[idp] : B[idp],
               1);
        break;
      case 'G':
        scanf(" %c", &time);
        if (golv) {
          if (time == 'A') pb++;
          else pa++;
        }
        golv = 1;
        break;
      case 'S':
        golv = 1;
        break;
      }}
    printf("%d X %d\n", pa, pb);
  }
  return 0;
}
