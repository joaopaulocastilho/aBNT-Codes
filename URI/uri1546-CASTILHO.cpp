#include<stdio.h>
#include<string.h>

int main(void) {
  int n, k, id;
  char nomes[4][51];
  strcpy(nomes[0], "Rolien"); strcpy(nomes[1], "Naej");
  strcpy(nomes[2], "Elehcim"); strcpy(nomes[3], "Odranoel");
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &id); id--;
      printf("%s\n", nomes[id]);
    }}
  return 0;
}
