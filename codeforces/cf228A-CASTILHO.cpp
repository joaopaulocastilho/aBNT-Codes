#include <iostream>

using namespace std;

int main(void) {
  int flag, i, j, v[11], resp;
  for (resp = i = 0; i < 4; i++) {
    cin >> v[i];
    for (flag = 1, j = 0; j < i; j++)
      if (v[i] == v[j]) flag = 0;
    resp += flag;
  }
  if (resp == 1) resp = 3;
  else if (resp == 3) resp = 1;
  else if (resp == 4) resp = 0;
  cout << resp << endl;
}
