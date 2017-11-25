#include <stdio.h>
#include <string.h>

#define MAX 112

void f_lower(char s[], int n) {
  int i;
  for (i = 0; i < n; i++)
    if (s[i] >= 'A' && s[i] <= 'Z')
      { s[i] -= 'A'; s[i] += 'a'; }
}

void f_upper(char s[], int n) {
  int i;
  for (i = 0; i < n; i++)
    if (s[i] >= 'a' && s[i] <= 'z')
      { s[i] -= 'a'; s[i] += 'A'; }
}

int main(void) {
  int n, minu = 0, maiu = 0, i;
  char s[MAX];
  scanf("%s", s);
  n = strlen(s);
  for (i = 0; i < n; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') minu++;
    else maiu++;
  }
  if (minu >= maiu) f_lower(s, n);
  else f_upper(s, n);
  printf("%s\n", s);
  return 0;
}
