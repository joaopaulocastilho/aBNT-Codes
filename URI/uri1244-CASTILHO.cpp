#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 61

int ind[MAX];
char str[MAX][MAX];

int cmp(const void *a, const void *b) {
  int n1 = (int)strlen(str[*(int*)a]), n2 = (int)strlen(str[*(int*)b]);
  return n2 - n1;
}

int main(void) {
  int casos, i, j, flag; char c;
  scanf("%d ", &casos);
  while (casos--) {
    memset(str, 0, sizeof(str));
    for (flag = 1, j = i = 0; flag; ) {
      scanf("%c", &c);
      if (c == ' ') { ind[i] = i; i++; j = 0; continue; }
      if (c == '\n') { ind[i] = i; flag = 0; i++; continue; }
      str[i][j++] = c;
    }
    qsort(ind, i, sizeof(int), &cmp);
    for (j = 0; j < i; j++) {
      if (j > 0) printf(" ");
      printf("%s", str[ind[j]]);
    }
    printf("\n");
  }
  return 0;
}
