#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

#define MAX 300
#define PUSH 1
#define POP 2

string source, target;
set<vector<int> > ans;
vector<int> mov;
stack<char> st;

void bt(int ids, int idt){
  char aux;
  if(idt == (int)target.size()){
    for(vector<int>::iterator it = mov.begin(); it != mov.end(); ++it){
      if(it != mov.begin()) cout << " ";
      cout << ((*it) == PUSH ? "i" : "o");
    }
    cout << "\n";
    return;
  }
  if(ids < (int)source.size()){
    st.push(source[ids]);
    mov.push_back(PUSH);
    bt(ids+1, idt);
    st.pop();
    mov.erase(mov.end() - 1);
  }
  if(!st.empty()){
    if(st.top() == target[idt]){
      aux = st.top();
      st.pop();
      mov.push_back(POP);
      bt(ids, idt+1);
      st.push(aux);
      mov.erase(mov.end() - 1);
    }
  }  
}

int main(void){
  int ok, first;
  int checasource[MAX], checatarget[MAX];
  while(cin >> source){
    ans.clear();
    mov.clear();
    while(!st.empty()) st.pop();
    cin >> target;
    cout << "[\n";
    if(target.size() == source.size()){
      ok = 1;
      for(int i = 0; i < 300; i++){ checasource[i] = 0; checatarget[i] = 0; }
      for(int i = 0; i < (int)source.size(); i++){ checasource[source[i]]++; checatarget[target[i]]++; }
      for(int i = 0; i < 300; i++){ if(checasource[i] != checatarget[i]) ok = 0; }
      if(ok){
	st.push(source[0]);
	mov.push_back(PUSH);
	bt(1, 0);
	for(set<vector<int> >::const_iterator it = ans.begin(); it != ans.end(); ++it){
	  first = 1;
	  for(vector<int>::const_iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2){
	    if(!first) cout << " ";
	    first = 0;
	    cout << ((*it2) == PUSH ? "i" : "o");
	  }
	  cout << "\n";
	}
      }
    }
    cout << "]\n";
  }
  return 0;
}
