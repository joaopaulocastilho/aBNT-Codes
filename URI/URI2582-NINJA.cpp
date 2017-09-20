#include <stdio.h>

#define MAX 20

int main(void){
  char nomes[][MAX] = {"PROXYCITY", "P.Y.N.G.", "DNSUEY!", "SERVERS", "HOST!",
              "CRIPTONIZE", "OFFLINE DAY", "SALT", "ANSWER!", "RAR?",
              "WIFI ANTENNAS"};
  int a, b, n;

  scanf("%d", &n);
  while(n--){
    scanf("%d %d", &a, &b);
    printf("%s\n", nomes[a+b]);
  }
  return 0;
}
