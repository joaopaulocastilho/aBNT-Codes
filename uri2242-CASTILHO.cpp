#include<stdio.h>

#define MAX 112

int vogal(char c) {
  int i;
  char v[] = { "aeiou" };
  for (i = 0; i < 5; i++)
    if (c == v[i]) return 1;
  return 0;
}

int main(void) {
  char str[MAX], vog[MAX];
  int i, j, resp = 1;
  scanf("%s", str);
  for (j = i = 0; str[i] != '\0'; i++)
    if (vogal(str[i])) vog[j++] = str[i];
  for (i = 0, j--; i < j; i++, j--)
    resp &= vog[i] == vog[j];
  printf("%c\n", resp ? 'S' : 'N');
  return 0;
}
