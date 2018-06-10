#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 1123

int main(void) {
  int n, i, atual[MAX], cod[MAX], resp, maior, tmp;
  char c;
  cin >> n;
  getchar();
  for (i = 0; i < n; i++) {
    scanf("%c", &c);
    atual[i] = c - '0';
  }
  getchar();
  for (resp = i = 0; i < n; i++) {
    scanf("%c", &c);
    cod[i] = c - '0';
    maior = max(cod[i], atual[i]);
    tmp = (10 - maior) + min(cod[i], atual[i]);
    resp += min(abs(atual[i] - cod[i]), tmp);
  }
  cout << resp << endl;
  return 0;
}
