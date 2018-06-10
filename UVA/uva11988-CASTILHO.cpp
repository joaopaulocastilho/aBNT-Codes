#include <stdio.h>
#include <iostream>
#include <string.h>
#include <list>

using namespace std;

#define MAX 112345

int main(void) {
  int j, cont, i, tam;
  char linha[MAX], aux[MAX];
  while (fgets(linha, MAX, stdin)) {
    list<char>resp;
    linha[strlen(linha) - 1] = '\0'; tam = strlen(linha);
    for (i = 0; i < tam; ) {
      if (linha[i] == '[') {
        for (i++, cont = 0; linha[i] != ']' && i < tam; i++) {
          if (linha[i] == '[') break;
          aux[cont++] = linha[i];
        }
        for (j = cont - 1; j >= 0; j--)
          resp.push_front(aux[j]);
        continue;
      }
      if (linha[i] == ']') { i++; continue; }
      resp.push_back(linha[i]);
      i++;
    }
    for (list<char>::iterator it = resp.begin(); it != resp.end(); ++it)
      cout << *it;
    printf("\n");
  }
  return 0;
}
