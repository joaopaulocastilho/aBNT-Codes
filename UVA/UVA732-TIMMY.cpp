#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>


#define PUSH 1
#define POP 2

using namespace std;

int main(void){
  string str;
  string source, target;
  vector<int> v;
  stack<char> st;
  vector<vector<int> > ans;
  vector<int> mov;
  int words[340], wordt[340], dif;
  while(cin >> source){
    ans.clear();
    v.clear();
    mov.clear();
    while(!st.empty()) st.pop();
    cin >> target;
    cout << "[\n";
    dif = 0;
    for(int i = 0; i < 30; i++){ words[i] = 0; wordt[i] = 0; }
    for(int i = 0; i < (int)source.size(); i++){ words[source[i]]++; wordt[target[i]]++; }
    for(int i = 0; i < 30; i++) if(words[i] != wordt[i]) dif = 1;
    if(source.size() == target.size() && !dif){
      for(int i = 0; i < (int)source.size(); i++) v.push_back(PUSH);
      for(int i = 0; i < (int)target.size(); i++) v.push_back(POP);
      do{
	str.clear();
	mov.clear();
	while(!st.empty()) st.pop();
	int push = 0, indexsource = 0, indextarget = 0, certo = 1;
	for(auto it = v.begin(); it != v.end(); it++){
	  if((*it) == PUSH){ st.push(source[indexsource++]); push++; mov.push_back(PUSH); }
	  else{
	    if(push > 0 && st.top() == target[indextarget++]){
	      push--;
	      mov.push_back(POP);
	      st.pop();
	    }
	    else{ certo = 0; break; }
	  }
	}
	if(certo) ans.push_back(mov);
      } while(next_permutation(v.begin()+1, v.end()));
    }
    for(auto it = ans.begin(); it != ans.end(); ++it){
      int primeiro = 1;
      for(auto it2 = (*it).begin(); it2 != (*it).end(); ++it2){
	if(!primeiro) cout << " ";
	primeiro = 0;
	if((*it2) == PUSH) cout << "i";
	else cout << "o";
      }
      cout << "\n";
    }
    cout << "]\n";
  }
  return 0;
}
