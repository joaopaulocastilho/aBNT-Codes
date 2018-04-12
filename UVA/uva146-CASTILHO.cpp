#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 112

int main(void) {
  char s[MAX];
  while (fgets(s, MAX, stdin), s[0] != '#') {
    s[strlen(s) - 1] = '\0';
    if (next_permutation(s, s + strlen(s))) printf("%s\n", s);
    else printf("No Successor\n");
  }
  return 0;
}
