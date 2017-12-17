#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 112

int cmp (const void *a, const void *b){
  return *(char *)a - *(char *)b;
}

int main(void){
  int t, n, i, dif;
  char str[MAX], str1[MAX];

  scanf("%d", &t);
  while(t--){
    scanf("%d ", &n);
    scanf("%s", str);
    strcpy(str1, str);
    qsort(str1, strlen(str1), sizeof(char), &cmp);
    for(i = dif = 0; i < strlen(str); i++) if(str[i] != str1[i]) dif++;
    printf("There are%s the chance.\n", dif > 2 ? "n't" : "");
  }

  return 0;
}
