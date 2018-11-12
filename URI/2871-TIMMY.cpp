#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n, m, num, count = 0;
  while(cin >> n >> m){
    count = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	cin >> num;
	count += num;
      }
    }
    int saca = count/60;
    int litro = count%60;

    cout << saca << " saca(s) e " << litro << " litro(s)\n";
  }

  return 0;
}
