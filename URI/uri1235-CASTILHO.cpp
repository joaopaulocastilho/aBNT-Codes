#include <bits/stdc++.h>

using namespace std;

const int MAXV = 112;

int main(void) {
  int i, n, t;
  char s[MAXV];
  scanf("%d", &t);
  cin.getline(s, 0);
  while (t--) {
    cin.getline(s, MAXV);
    n = strlen(s);
    //printf("%s\n", s);
    for (i = n / 2 - 1; i >= 0; i--) printf("%c", s[i]);
    for (i = n - 1; i >= n / 2; i--) printf("%c", s[i]);
    printf("\n");
  }
  return 0;
}
