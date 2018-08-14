#include <iostream>

using namespace std;

int main(void) {
  int va, ea, sa, vb, eb, sb;
  int ptsa, ptsb, resp;
  cin >> va >> ea >> sa >> vb >> eb >> sb;
  ptsa = va * 3 + ea;
  ptsb = vb * 3 + eb;
  if (ptsa == ptsb &&
      sa == sb) {
    cout << "=" << endl;
    return 0;
  }
  if (ptsa > ptsb) resp = 1;
  else if (ptsb > ptsa) resp = 2;
  else if (sa > sb) resp = 1;
  else resp = 2;
  if (resp == 1) cout << "C";
  else cout << "F";
  cout << endl;
}
