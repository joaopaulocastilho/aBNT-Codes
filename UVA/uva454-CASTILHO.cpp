#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

#define MAX 1124

int cmp(const void *a, const void *b) {
  return *(char*)a - *(char*)b;
}

void remove_spaces(char s[], char aux[]) {
  int i, cont, tam = strlen(s);
  for (cont = i = 0; i < tam; i++)
    if (s[i] != ' ') aux[cont++] = s[i];
  aux[cont] = '\0';
}

int main(void) {
  int c, tam, first;
  char s[MAX], sse[MAX], sord[MAX];
  scanf("%d ", &c);
  while (c--) {
    map<string, string>dic;
    while (fgets(s, MAX, stdin) && s[0] != '\n') {
      s[strlen(s) - 1] = '\0';
      remove_spaces(s, sse); tam = strlen(sse);
      strcpy(sord, sse); qsort(sord, tam, sizeof(char), &cmp);
      dic[string(s)] = string(sord);
    }
    for (map<string, string>::iterator it = dic.begin(); it != dic.end(); ++it) {
      first = 1;
      for (map<string, string>::iterator it2 = it; it2 != dic.end(); ++it2) {
        if (first) { first = 0; continue; }
        if (it->second == it2->second)
          printf("%s = %s\n", it->first.c_str(), it2->first.c_str());
      }
    }
    if (c) printf("\n");
  }
  return 0;
}
