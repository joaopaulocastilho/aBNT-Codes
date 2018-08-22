#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 4123456

int bit[MAX], n;

void update(int x, int val){
  for(; x <= n; x+= x & -x) bit[x] += val;
}

int query(int x){
  int sum = 0;
  for(; x > 0; x -= x & -x) sum += bit[x];
  return sum;
}

int main(void){
  int num;
  cin >> n;
  vector<int> v;
  memset(bit, 0, sizeof(bit));
  for(int i = 0; i < n; i++){
    cin >> num;
    int ans = num - (query(num));
    v.push_back(ans);
    update(num, 1);
  }
  for(int i = 0; i < n; i++){
    if(i != 0) cout << " ";
    cout << v[i];
  }
  cout << endl;
  return 0;
}
