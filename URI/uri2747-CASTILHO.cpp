#include <iostream>

using namespace std;

int main(void) {
  int i, j;
  for (i = 0; i < 39; i++) cout << "-";
  cout << endl;
  for (j = 0; j < 5; j++) {
    cout << "|";
    for (i = 1; i < 38; i++) cout << " ";
    cout << "|" << endl;
  }
  for (i = 0; i < 39; i++) cout << "-";
  cout << endl;
  return 0;
}
