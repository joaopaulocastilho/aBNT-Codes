#include <iostream>
#include <string>

using namespace std;

int main(void){
  string palavra;
  int first = 1;
  while(cin >> palavra){
    if(first) first = 0; else  cout << " ";
    int gago = 1;
    for(int i = 0; i < 2 && (int)palavra.size() >= 4; i++)
      if(palavra[i] != palavra[i+2]) gago = 0;
    if(!gago || palavra.size() < 4) cout << palavra;
    else
      for(int i = 2; i < (int)palavra.size(); i++)
	cout << palavra[i];
  }
  cout << endl;
  return 0;
}
