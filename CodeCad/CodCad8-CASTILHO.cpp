#include <iostream>

using namespace std;

int main(void) {
  int i, n, first = 1;
  cin >> n;
  for (i = 1; i <= n; i++) {
    if (n % i == 0) {
      if (first) first = 0;
      else cout << " ";
      cout << i;
    }
  }
  cout << endl;
  return 0;
}
