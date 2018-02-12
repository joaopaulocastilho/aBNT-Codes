#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 1123

int main(void) {
  int n, i, tam; char str[MAX];
  scanf("%d ", &n);
  while (n--) {
    fgets(str, MAX, stdin);
    str[strlen(str) - 1] = '\0';
    tam = strlen(str);
    for (i = 0; i < tam; i++)
      if ((str[i] >= 'A' && str[i] <= 'Z') ||
          (str[i] >= 'a' && str[i] <= 'z')) str[i] += 3;
    for (i = 0; i < ceil((double)tam / 2); i++) str[i]--;
    for (i = tam - 1; i >= 0; i--) printf("%c", str[i]);
    printf("\n");
  }
  return 0;
}
