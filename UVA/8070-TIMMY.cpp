#include <bits/stdc++.h>

using namespace std;

int main(void){
  stack<int> st;
  int k, n, sum, qtd, add;
  string c;
  while(cin >> n >> k){
    sum = 0;
    while(k--){
      cin >> c;
      if(c == "undo"){
        cin >> qtd;
        while(qtd--) st.pop();
      }
      else{
        int num;
        stringstream numero(c);
        numero >> num;
        st.push(num);
      }
    }
    while(!st.empty()){
      sum += st.top();
      st.pop();
    }
    add = 10000* n;
    cout << (sum + add) % n << "\n";
  }
  return 0;
}
