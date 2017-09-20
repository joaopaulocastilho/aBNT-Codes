#include<stdio.h>

int main(void) {
  double n, media = .0;
  int cont = 0;
  char lixo[112];
  while (fgets(lixo, 112, stdin)) {
    scanf("%lf", &n);
    media += n; cont++;
  }
  printf("%.1lf\n", media / cont);
  return 0;
}
