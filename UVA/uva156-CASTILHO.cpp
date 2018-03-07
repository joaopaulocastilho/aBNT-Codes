#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

#define MAX 112
#define MAXP 1123
#define ALFABETO 26

int letra(char c) {
  if (c >= 'A' && c <= 'Z') return c - 'A';
  return c - 'a';
}

int main(void) {
  int i, tam, cont, j, k, resp, qtd[MAXP], flag;
  char str[MAX], content[MAXP][31], content_atual[31];
  set<string>palavras;
  memset(content, 0, sizeof(content));
  for (cont = 0; scanf("%s", str), strcmp(str, "#"); cont++) {
    tam = strlen(str); qtd[cont] = 0;
    for (i = 0; i < tam; i++) {
      content[cont][letra(str[i])]++;
      qtd[cont]++;
    }
    if (palavras.find(string(str)) == palavras.end())
      palavras.insert(string(str));
    }
  k = 0;
  for (set<string>::iterator it = palavras.begin();
       it != palavras.end(); ++it) {
    tam = (*it).length(); resp = 0;
    memset(content_atual, 0, sizeof(content_atual));
    for (j = 0; j < tam; j++) content_atual[letra((*it)[j])]++;
    for (i = 0; i < cont; i++) {
      for (flag = 1, j = 0; j < ALFABETO; j++)
        flag &= (content_atual[j] == content[i][j]);
      if (flag) resp++;
    }
    if (resp == 1) printf("%s\n", (*it).c_str());
    k++;
  }
  return 0;
}
