#include<stdio.h>

#define DIA_SEC 86400

int main(void) {
  int diaIni, diaFim, hi, mi, si, hf;
  int mf, sf, seg_inicial, seg_final, total, aux;
  char lixo[10];
  scanf("%s %d", lixo, &diaIni);
  scanf("%d : %d : %d", &hi, &mi, &si);
  scanf("%s %d", lixo, &diaFim);
  scanf("%d : %d : %d", &hf, &mf, &sf);
  seg_inicial = DIA_SEC * diaIni;
  seg_inicial += si + mi * 60 + hi * 3600;
  seg_final = DIA_SEC * diaFim;
  seg_final += sf + mf * 60 + hf * 3600;
  total = seg_final - seg_inicial;
  aux = total;
  aux /= DIA_SEC;
  printf("%d dia(s)\n", aux);
  total -= DIA_SEC * aux;
  aux = (total > 0) ? total : 0;
  aux /= 3600;
  printf("%d hora(s)\n", aux);
  total -= 3600 * aux;
  aux = (total > 0) ? total : 0;
  aux /= 60;
  printf("%d minuto(s)\n", aux);
  total -= 60 * aux;
  aux = (total > 0) ? total : 0;
  printf("%d segundo(s)\n", aux);
  return 0;
}
