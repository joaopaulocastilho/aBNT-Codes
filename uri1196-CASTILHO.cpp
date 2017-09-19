#include <stdio.h>

char fix(char c) {
  if (c == 'B') return 'V';
  if (c == 'C') return 'X';
  if (c == 'D') return 'S';
  if (c == 'E') return 'W';
  if (c == 'F') return 'D';
  if (c == 'G') return 'F';
  if (c == 'H') return 'G';
  if (c == 'I') return 'U';
  if (c == 'J') return 'H';
  if (c == 'K') return 'J';
  if (c == 'L') return 'K';
  if (c == 'M') return 'N';
  if (c == 'N') return 'B';
  if (c == 'O') return 'I';
  if (c == 'P') return 'O';
  if (c == 'R') return 'E';
  if (c == 'S') return 'A';
  if (c == 'T') return 'R';
  if (c == 'U') return 'Y';
  if (c == 'V') return 'C';
  if (c == 'X') return 'Z';
  if (c == 'Y') return 'T';
  if (c == 'W') return 'Q';
  if (c == '\'') return ';';
  if (c == '[') return 'P';
  if (c == ']') return '[';
  if (c == '/') return '.';
  if (c == '\\') return ']';
  if (c == ',') return 'M';
  if (c == '.') return ',';
  if (c == ';') return 'L';
  if (c == '=') return '-';
  if (c == '-') return '0';
  if (c == '0') return '9';
  if (c == '9') return '8';
  if (c == '8') return '7';
  if (c == '7') return '6';
  if (c == '6') return '5';
  if (c == '5') return '4';
  if (c == '4') return '3';
  if (c == '3') return '2';
  if (c == '2') return '1';
  if (c == '1') return '`';
  return c;
}

int main(void) {
  char c;
  while (scanf("%c", &c) != EOF) printf("%c", fix(c));
  return 0 ;
}
