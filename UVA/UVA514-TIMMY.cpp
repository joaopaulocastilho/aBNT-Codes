#include <iostream>
#include <stack>

using namespace std;

int main(void){
  stack<int> st;
  int sz, n, val, stop, flag;
  while(cin >> sz, sz != 0){
    stop = 0;
    while(!stop){
      flag = 0;
      n = 1;
      while(!st.empty()) st.pop();
      for(int i = 0; i < sz && !stop; i++){
	cin >> val;
	if(flag) continue;
	if(i + val == 0){ stop = 1; continue; }
	if(n <= val){
	  while(n <= val) st.push(n++);
	  st.pop();
	}
	else if(n > val){
	  if(st.top() != val) flag = 1;
	  else st.pop();
	}
      }
      if(!stop){
	if(flag) cout << "No\n";
	else cout << "Yes\n";
      }
    }
    cout << "\n";
  }
  return 0;
}
