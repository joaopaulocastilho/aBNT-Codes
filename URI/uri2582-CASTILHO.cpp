#include <stdio.h>

void print_musica(int n) {
  if (n == 0) printf("PROXYCITY\n");
  else if (n == 1) printf("P.Y.N.G.\n");
  else if (n == 2) printf("DNSUEY!\n");
  else if (n == 3) printf("SERVERS\n");
  else if (n == 4) printf("HOST!\n");
  else if (n == 5) printf("CRIPTONIZE\n");
  else if (n == 6) printf("OFFLINE DAY\n");
  else if (n == 7) printf("SALT\n");
  else if (n == 8) printf("ANSWER!\n");
  else if (n == 9) printf("RAR?\n");
  else if (n == 10) printf("WIFI ANTENNAS\n");
}

int main(void) {
  int n, n1, n2;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &n1, &n2);
    print_musica(n1 + n2);
  }
  return 0;
}
