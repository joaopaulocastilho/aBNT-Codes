#include <bits/stdc++.h>

using namespace std;

int main(void){
  int n, k, num, i;
  deque<int> dq;
  
  scanf("%d %d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    dq.push_back(num);
  }
  while(!dq.empty() && k >= dq.front()) dq.pop_front();
  while(!dq.empty() && k >= dq.back()) dq.pop_back();
  printf("%d\n", n - (int)dq.size());
  
  return 0;
}
