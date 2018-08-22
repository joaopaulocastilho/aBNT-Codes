#include <iostream>

using namespace std;

int main(void){
  int n; cin >> n;
  while(n--){
    double c1, c2, cc1, cc2;
    cin >> c1 >> c2 >> cc1 >> cc2;
    int flag = 0;
    for(int i = 1; i <= 100; i++){
      c1 += (int)((cc1/100)*c1); c2 += (int)((cc2/100)*c2);
      if(c1 > c2){ cout << i << " anos.\n"; flag = 1; break; }
    }
    if(!flag) cout << "Mais de 1 seculo.\n";
  }

  return 0;
}
