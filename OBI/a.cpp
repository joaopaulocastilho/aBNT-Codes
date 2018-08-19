#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

int main(void) {
  char p[MAXV];
  while (fgets(p, MAXV, stdin)) {
    if (p[0] == 'e') printf("ingles\n");
    else if (p[0] == 'd') printf("frances\n");
    else if (p[0] == 'n') printf("portugues\n");
    else printf("caiu\n");
  }
  return 0;
}
