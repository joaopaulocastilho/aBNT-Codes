#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 112345
#define MAXP 69
#define TAM 60

char page[MAXP][MAXP];

char c5[][7][7] =
  {
    { ".***..", "*...*.", "*****.", "*...*.", "*...*." }, //A
    { "****..", "*...*.", "****..", "*...*.", "****.." }, //B
    { ".****.", "*...*.", "*.....", "*.....", ".****." }, //C
    { "****..", "*...*.", "*...*.", "*...*.", "****.." }, //D
    { "*****.", "*.....", "***...", "*.....", "*****." }, //E
    { "*****.", "*.....", "***...", "*.....", "*....." }, //F
    { ".****.", "*.....", "*..**.", "*...*.", ".***.." }, //G
    { "*...*.", "*...*.", "*****.", "*...*.", "*...*." }, //H
    { "*****.", "..*...", "..*...", "..*...", "*****." }, //I
    { "..***.", "...*..", "...*..", "*..*..", ".**..." }, //J
    { "*...*.", "*..*..", "***...", "*..*..", "*...*." }, //K
    { "*.....", "*.....", "*.....", "*.....", "*****." }, //L
    { "*...*.", "**.**.", "*.*.*.", "*...*.", "*...*." }, //M
    { "*...*.", "**..*.", "*.*.*.", "*..**.", "*...*." }, //N
    { ".***..", "*...*.", "*...*.", "*...*.", ".***.." }, //O
    { "****..", "*...*.", "****..", "*.....", "*....." }, //P
    { ".***..", "*...*.", "*...*.", "*..**.", ".****." }, //Q
    { "****..", "*...*.", "****..", "*..*..", "*...*." }, //R
    { ".****.", "*.....", ".***..", "....*.", "****.." }, //S
    { "*****.", "*.*.*.", "..*...", "..*...", ".***.." }, //T
    { "*...*.", "*...*.", "*...*.", "*...*.", ".***.." }, //U
    { "*...*.", "*...*.", ".*.*..", ".*.*..", "..*..." }, //V
    { "*...*.", "*...*.", "*.*.*.", "**.**.", "*...*." }, //W
    { "*...*.", ".*.*..", "..*...", ".*.*..", "*...*." }, //X
    { "*...*.", ".*.*..", "..*...", "..*...", "..*..." }, //Y
    { "*****.", "...*..", "..*...", ".*....", "*****." }, //Z
    { "......", "......", "......", "......", "......" } //BLANK
  };

void print_page() {
  int i, j;
  for (i = 0; i < TAM; i++) {
    for (j = 0; j < TAM; j++)
      printf("%c", page[i][j]);
    printf("\n");
  }
  printf("\n");
  for (i = 0; i < 60; i++) printf("-");
  printf("\n\n");
}

void inicializa() {
  int i, j;
  for (i = 0; i < TAM; i++)
    for (j = 0; j < TAM; j++)
      page[i][j] = '.';
}

void print_letter(int l) {
  int i, j;
  for (i = 0; i < 5; i++){
    for (j = 0; j < 6; j++)
      printf("%c", c5[l][i][j]);
    printf("\n");
  }
  printf("\n");
}

void coloca_c5(int r, int col, char c) {
  int i, j, ind = c - 'A';
  if (c == ' ') ind = 26;
  for (i = 0; i < 5; i++)
    for (j = 0; j < 6; j++) {
      if (c5[ind][i][j] == '.') continue;
      page[r + i][col + j] = c5[ind][i][j];
    }
}

void coloca_metade_c5(int r, int col, char c, int pos) {
  int i, j, ind = c - 'A', n;
  if (c == ' ') ind = 26;
  for (i = 0; i < 5; i++)
    for (j = 0; j < 3; j++) {
      if (pos == 1) n = j;
      else n = j + 3;
      if (c5[ind][i][n] == '.') continue;
      page[r + i][col + j] = c5[ind][i][n];
    }}

void grava_centro(char text[], int tipo, int linha) {
  int ini, i, sup, inf, tam = strlen(text);
  if (tipo == 5) {
    inf = max(0, (tam / 2) - 5); sup = min(tam, inf + 10);
    ini = 30 - ((min(10, tam) * 6) / 2);
    if (tam & 1 && tam > 10) {
      coloca_metade_c5(linha, 0, text[inf], 2);
      inf++; ini += 3;
    }
    for (i = inf; i < sup; i++) {
      coloca_c5(linha, ini, text[i]);
      ini += 6;
    }
    if (tam & 1 && tam > 10) coloca_metade_c5(linha, 57, text[sup], 1);
  }
  else {
    inf = max(0, (tam / 2) - 30); sup = min(tam, inf + 60);
    ini = max(30 - (tam / 2), 0);
    for (i = inf; i < sup; i++) {
      if (text[i] != ' ') page[linha][ini] = text[i];
      ini++;
    }}}

void grava_j(char text[], int tipo, int linha, int flag) {
  int ini, i, sup, inf, tam = strlen(text);
  if (tipo == 5) {
    if (flag) {
      inf = max(0, tam - 10); sup = tam;
      ini = 60 - (min(10, tam) * 6);
    } else {
      inf = 0; sup = min(10, tam);
      ini = 0;
    }
    for (i = inf; i < sup; i++) {
      coloca_c5(linha, ini, text[i]);
      ini += 6;
    }}
  else {
    if (flag) {
      inf = max(0, tam - 60); sup = tam;
      ini = 60 - min(60, tam);
    } else {
      inf = 0; sup = min(60, tam);
      ini = 0;
    }
   for (i = inf; i < sup; i++) {
      if (text[i] != ' ') page[linha][ini] = text[i];
      ini++;
   }}}

void grava_p(char text[], int tipo, int linha, int coluna) {
  int i, c = coluna, tam = strlen(text);
  for (i = 0; i < tam; i++) {
    if (c > 60 || coluna > 60) break;
    if (tipo == 5) {
      coloca_c5(linha, c, text[i]);
      c += 6;
      continue;
    }
    if (text[i] != ' ') page[linha][coluna] = text[i];
    coluna++;
  }}

int char_num(char str[]) {
  int i, ret = 0, mul = 1;
  for (i = 0; i < (int)strlen(str); i++) {
    ret *= mul;
    ret += str[i] - '0';
    mul = 10;
  }
  return ret;
}

int main(void) {
  int i, tipo, op, r, j, c;
  char linha[MAX], text[MAX], aux[20];
  inicializa();
  while (fgets(linha, MAX, stdin)) {
    if (strcmp(linha, ".EOP\n") == 0) {
      print_page();
      inicializa();
      continue;
    }
    for (i = 0; linha[i] != '.'; i++);
    i++; op = linha[i];
    if (op == 'C' || op == 'R' || op == 'L' || op == 'P') {
      for (i++; linha[i] != 'C'; i++);
      i++; tipo = linha[i] - '0';
      for (i++; linha[i] == ' '; i++);
      for (j = 0; linha[i] != ' '; i++) aux[j++] = linha[i];
      aux[j] = '\0';
      r = char_num(aux);
      if (op == 'P') {
        for (i++, j = 0; linha[i] != ' '; i++) aux[j++] = linha[i];
        aux[j] = '\0';
        c = char_num(aux);
      }
      for (i++; linha[i] != '|'; i++);
      for (j = 0, i++; linha[i] != '|'; i++) text[j++] = linha[i];
      text[j] = '\0';
      if (op == 'C') grava_centro(text, tipo, r - 1);
      else if (op == 'R') grava_j(text, tipo, r - 1, 1);
      else if (op == 'L') grava_j(text, tipo, r - 1, 0);
      else grava_p(text, tipo, r - 1, c - 1);
    }}
  return 0;
}
