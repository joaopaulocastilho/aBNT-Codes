#include <stdio.h>
#include <string.h>

#define MAX 1123

int main(void) {
  int i, j = 0; char s1[MAX], s2[MAX], aux[MAX];
  scanf("%s %s", s1, s2);
  //printf("%s %s", s1, s2);
  for (i = strlen(s2) - 1; i >= 0; i--)
    aux[j++] = s2[i];
  aux[j] = 0;
  //printf(" oau = %s\n", aux);
  if (strcmp(aux, s1)) printf("NO\n");
  else printf("YES\n");
  return 0;
}
