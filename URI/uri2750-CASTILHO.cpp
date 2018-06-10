#include <iostream>

using namespace std;

int main(void) {
  int i;
  for (i = 0; i < 39; i++) cout << "-";
  cout << endl;
  cout << "|  decimal  ";
  cout << "|  octal  ";
  cout << "|  Hexadecimal  | ";
  cout << endl;
  for (i = 0; i < 39; i++) cout << "-";
  cout << endl;
  for (i = 0; i < 16; i++) {
    cout << "|";
    if (i < 10) cout << " ";
    cout << "     " << i;
    cout << "    |";
    if (i <= 7) cout << " ";
    cout << "   " << oct << i;
    cout  << "    |       " << i << "       |" << endl;
  }
  return 0;
}
