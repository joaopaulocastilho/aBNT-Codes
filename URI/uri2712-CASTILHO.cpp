#include <stdio.h>
#include <string.h>

int valida(char c, int n) {
  if (n >= 0 && n < 3 && c >= 'A' && c <= 'Z') return 1;
  if (n == 3 && c == '-') return 1;
  if (n >= 4 && n < 8 && c >= '0' && c <= '9') return 1;
  return 0;
}

int main(void) {
  int n, flag, i;
  char placa[21];
  scanf("%d ", &n);
  while (n--) {
    flag = 1;
    fgets(placa, 21, stdin); placa[strlen(placa) - 1] = '\0';
    if (strlen(placa) != 8) flag = 0;
    for (i = 0; flag && i < 8; i++) flag &= valida(placa[i], i);
    if (flag) {
      if (placa[7] == '1' || placa[7] == '2') printf("MONDAY\n");
      else if (placa[7] == '3' || placa[7] == '4') printf("TUESDAY\n");
      else if (placa[7] == '5' || placa[7] == '6') printf("WEDNESDAY\n");
      else if (placa[7] == '7' || placa[7] == '8') printf("THURSDAY\n");
      else if (placa[7] == '9' || placa[7] == '0') printf("FRIDAY\n");
    } else printf("FAILURE\n");
  }
  return 0;
}
