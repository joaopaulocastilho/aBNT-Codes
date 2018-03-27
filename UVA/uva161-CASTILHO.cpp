#include <stdio.h>

#define MAX 112
#define TOTAL 3600 * 5
#define G 0
#define O 1
#define R 2

struct sem_t { int ta, s; sem_t() {}
  sem_t(int _ta, int _s): ta(_ta), s(_s) {} };

int main(void) {
  int n, sem[MAX], menor, i, tempo, hora, minuto, segundo, flag, resp;
  sem_t estado[MAX];
  while (scanf("%d", &sem[0]), sem[0]) {
    for (menor = sem[0], n = 1; sem[n - 1] != 0; n++) {
      scanf("%d", &sem[n]);
      if (sem[n] && sem[n] < menor) menor = sem[n];
    }
    for (i = 0; i < n; i++)
      estado[i] = sem_t(menor - 5, G);
    n--;
    for (i = 0; i < n; i++)
      if (sem[i] == menor) estado[i] = sem_t(menor - 5, O);
    for (flag = 1, tempo = menor - 5; flag; tempo++) {
      if (tempo > TOTAL) break;
      for (i = 0; i < n; i++) {
        //printf("tempo = %d | i = %d | ta = %d | es = %d\n",
        //   tempo, i, estado[i].ta, estado[i].s);
        if (estado[i].s == G) {
          if (estado[i].ta + 1 == sem[i] - 5)
            estado[i] = sem_t(estado[i].ta + 1, O);
          else estado[i].ta++;
        } else if (estado[i].s == O) {
          if (estado[i].ta + 1 == sem[i])
            estado[i] = sem_t(0, R);
          else estado[i].ta++;
        } else {
          if (estado[i].ta + 1 == sem[i]) estado[i] = sem_t(0, G);
          else estado[i].ta++;
        }
      }
      for (resp = 1, i = 0; i < n; i++)
        resp &= (estado[i].s == G);
      if (resp) flag = 0;
    }
    if (tempo > TOTAL) printf("Signals fail to synchronise in 5 hours\n");
    else {
      segundo = tempo;
      minuto = segundo / 60;
      segundo = segundo % 60;
      hora = minuto / 60;
      minuto = minuto % 60;
      printf("%s%d:%s%d:%s%d\n",
             hora < 10 ? "0" : "", hora, minuto < 10 ? "0" : "", minuto,
             segundo < 10 ? "0" : "", segundo);
    }
  }
  return 0;
}
