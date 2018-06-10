#include <iostream>

using namespace std;

int main(void) {
  int i, j, n, m, resp, flag, tmp;
  cin >> n >> m;
  for (resp = i = 0; i < n; i++) {
    for (flag = 1, j = 0; j < m; j++) {
      cin >> tmp;
      flag &= (tmp != 0);
    }
    resp += flag;
  }
  cout << resp << endl;
  return 0;
}
