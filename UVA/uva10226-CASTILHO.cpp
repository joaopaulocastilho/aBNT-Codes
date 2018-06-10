#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

#define MAX 31

int main(void) {
  int casos, total, tmp, first = 1;
  char tr[MAX];
  scanf("%d ", &casos);
  while (casos--) {
    if (first) first = 0;
    else printf("\n");
    map<string, int>arv; total = 0;
    while (fgets(tr, MAX, stdin)) {
      if (tr[0] == '\n') break;
      tr[strlen(tr) - 1] = '\0';
      arv[string(tr)]++; total++;
    }
    for (map<string, int>::iterator it = arv.begin();
         it != arv.end(); ++it) {
      tmp = it->second;
      printf("%s %.4lf\n", (it->first).c_str(),
             ((double)tmp/(double)total * 100));
    }
  }
  return 0;
}
