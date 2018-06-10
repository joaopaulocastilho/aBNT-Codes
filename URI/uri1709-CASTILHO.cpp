#include <iostream>

using namespace std;

int main(void) {
  int p1 = 1, p, resp;
  cin >> p;
  for (resp = 1; p1 != 0; resp++) {
    if (p1 < p / 2) p1 = p1 + p1 + 1;
    else p1 = (p1 + p1) % p;
  }
  cout << resp << endl;
  return 0;
}
