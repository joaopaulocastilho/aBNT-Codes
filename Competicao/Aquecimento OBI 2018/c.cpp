#include <iostream>
#include <cmath>

using namespace std;

int main(void){
  int n; cin >> n;
  int Jx = 0, Jy = 0, Fx = 0, Fy = 0;
  while(n--){
    int k, l; cin >> k >> l;
    for(int i = 0; i < l; i++){
      string linha; cin >> linha;
      for(int j = 0; j < (int)linha.size(); j++){
	if(linha[j] == 'J'){ Jx = i; Jy = j; }
	if(linha[j] == 'F'){ Fx = i; Fy = j; }
      }
    }
    long long int dist = (int)(sqrt((((Jx - Fx)*10)*((Jx-Fx)*10)) + (((Jy-Fy)*10)*((Jy-Fy)*10))));
    long long int ans = (int)(k/pow(0.99, dist));
    cout << ans << " dBs" << endl;
  }
  return 0;
}
