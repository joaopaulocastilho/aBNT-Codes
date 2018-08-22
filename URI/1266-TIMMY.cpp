#include <iostream>
#include <cmath>

using namespace std;

#define MAX 11234

int main(void){
  int n, v[MAX], i;
  while(cin >> n, n > 0){
    for(i = 0;i < n; i++){
      cin >> v[i];
    }
    int count = 0, ans = 0;
    for(i = 0; i < n && v[i] != 1; i++);
    int start = (i == n ? 0 : i);
    i++;
    while(i != start){
      if(v[i] == 1){
	ans += floor((double)count/2);
	count = 0;
      }
      else count++;
      i = (i+1)%n;
    }
    ans+= floor((double)count/2);
    if(start == 0 && v[n-1] == 0 && v[start] == 0) ans++;
    cout << ans << endl;
  }
  return 0;
}
