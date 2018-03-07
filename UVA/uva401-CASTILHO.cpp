#include <stdio.h>
#include <string.h>

#define MAX 112

char reverso(char c) {
  switch (c) {
  case 'A': return 'A'; break;
  case 'H': return 'H'; break;
  case 'I': return 'I'; break;
  case 'M': return 'M'; break;
  case 'O': return 'O'; break;
  case 'T': return 'T'; break;
  case 'U': return 'U'; break;
  case 'V': return 'V'; break;
  case 'W': return 'W'; break;
  case 'X': return 'X'; break;
  case 'Y': return 'Y'; break;
  case '1': return '1'; break;
  case '8': return '8'; break;
  case 'E': return '3'; break;
  case '3': return 'E'; break;
  case 'J': return 'L'; break;
  case 'L': return 'J'; break;
  case 'S': return '2'; break;
  case 'Z': return '5'; break;
  case '2': return 'S'; break;
  case '5': return 'Z'; break;
  }
  return 0;
}

int is_palindrome(char str[]) {
  int i, j;
  for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    if (str[i] != str[j]) return 0;
  return 1;
}

int is_mirrored(char str[]) {
  int i, tam = strlen(str);
  char aux[MAX];
  for (i = 0; i < tam; i++) {
    if (reverso(str[i])) aux[i] = reverso(str[i]);
    else return 0;
  }
  for (i = 0; i < tam; i++)
    if (str[i] != aux[(tam - 1) - i]) return 0;
  return 1;
}

int main(void) {
  int palindrome, mirrored;
  char str[MAX];
  while (fgets(str, MAX, stdin)) {
    str[strlen(str) - 1] = '\0';
    palindrome = is_palindrome(str);
    mirrored = is_mirrored(str);
    if (palindrome && mirrored) printf("%s -- is a mirrored palindrome.\n\n", str);
    else if (palindrome) printf("%s -- is a regular palindrome.\n\n", str);
    else if (mirrored) printf("%s -- is a mirrored string.\n\n", str);
    else printf("%s -- is not a palindrome.\n\n", str);
  }
  return 0;
}
