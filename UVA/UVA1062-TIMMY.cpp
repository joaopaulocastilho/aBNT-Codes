#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>


using namespace std;

#define MAX 1123

int main(void){
  char str[MAX];
  vector<stack<char> > vst;
  stack<char> st, aux;
  int len;
  int cs = 1;
  vector<stack<char> >::iterator it;
  while(scanf(" %s", str), str[0] != 'e' && str[1] != 'n' && str[2] != 'd'){
    vst.clear();
    while(!st.empty()) st.pop();
    len = strlen(str);
    for(int i = 0; i < len; i++){
      if(!i){ while(!st.empty()) st.pop(); st.push(str[i]); vst.push_back(st); }
      else{
	for(it = vst.begin(); it != vst.end(); ++it){
	  if((*it).top() >= str[i]){ (*it).push(str[i]); break; }
	}
	if(it == vst.end()){
	  while(!st.empty()) st.pop();
	  st.push(str[i]);
	  vst.push_back(st);
	}
      }
    }
    printf("Case %d: %d\n", cs++, (int)vst.size());
  }
  return 0;
}
