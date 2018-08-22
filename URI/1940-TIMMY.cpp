#include <iostream>
#include <cstring>
using namespace std;

#define MAX 512

int main(void){
  int v[MAX];
  int n, p; cin >> n >> p;
  memset(v, 0, sizeof(v));
  for(int i = 0; i < n*p; i++){
    int num; cin >> num;
    v[i%n] += num;
  }
  int maior = -1, idx;
  for(int i = 0; i < n; i++){
    if(v[i] >= maior){ maior = v[i]; idx = i; }
  }
  cout << idx+1 << endl;
  return 0;
}
