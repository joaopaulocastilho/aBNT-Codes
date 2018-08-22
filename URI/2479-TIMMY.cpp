#include <iostream>
#include <set>

using namespace std;

int main(void){
  set<string> st;
  int n; cin >> n;
  int comp, ncomp;
  comp = ncomp = 0;
  for(int i = 0;i < n; i++){
    string c;
    cin >> c;
    if(c == "+") comp ++; else ncomp ++;
    cin >> c; st.insert(c);
  }
  for(set<string>::iterator it = st.begin(); it != st.end(); ++it){
    cout << (*it) << endl;
  }
  cout << "Se comportaram: " << comp <<" | Nao se comportaram: " << ncomp << endl;
  return 0;
}
