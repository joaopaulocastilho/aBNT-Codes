#include<stdio.h>
#include<string.h>

#define MAX 112

int d;
char n[MAX];

int main(void) {
  int tam, flag, i, j;
  while (scanf("%d", &d), d) {
    scanf(" %s", n);
    for (flag = 1, tam = (int)strlen(n), j = i = 0; i < tam; i++)
      if (n[i] - '0' != d)
        if (!(flag && n[i] - '0' == 0)) {
          printf("%c", n[i]); flag = 0; j++;
        }
    if (!j) printf("0");
    printf("\n");
  }
  return 0;
}
