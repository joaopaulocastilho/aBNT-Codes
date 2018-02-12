#include <stdio.h>
#include <string.h>
#include <set>
#include <string>

using namespace std;

#define MAX 12

int main(void) {
  int n, i;
  char livro[MAX];
  while (scanf("%d", &n) != EOF) {
    set<string>bib;
    for (i = 0; i < n; i++) {
      scanf(" %s", livro);
      if (bib.find(string(livro)) == bib.end()) bib.insert(string(livro));
    }
    for (set<string>::iterator it = bib.begin(); it != bib.end(); ++it) {
      string aux = *it;
      printf("%s\n", aux.c_str());
    }
  }
  return 0;
}
