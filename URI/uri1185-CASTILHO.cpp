#include <iostream>

using namespace std;

#define MAT 12

int main(void) {
  int i, j, lim, cont;
  double m[MAT][MAT], resp;
  char op;
  cin >> op;
  for (i = 0; i < MAT; i++) for (j = 0; j < MAT; j++) cin >> m[i][j];
  for (cont = resp = 0, lim = MAT - 2, i = 0; i < MAT; i++, lim--)
    for (j = 0; j < MAT; j++) {
      if (j > lim) break;
      resp += m[i][j]; cont++;
      //cout << "i, j = " << i << " " << j << endl;
    }
  cout << ((op == 'S') ? resp : resp / cont) << endl;
  return 0;
}
