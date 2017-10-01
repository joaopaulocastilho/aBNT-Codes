#include<stdio.h>

#define MAX 1123

int main(void) {
  int pilha = 0, flag = 1;
  char c;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      if (pilha) flag = 0;
      printf("%scorrect\n", flag ? "" : "in");
      flag = 1; pilha = 0;
      continue;
    }
    if (c == '(') { pilha++; continue; }
    if (c == ')') {
      if (pilha > 0) pilha--;
      else flag = 0;
    }
  }
  return 0;
}
