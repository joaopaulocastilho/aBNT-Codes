#include <stdio.h>
#include <stack>
#include <string>
#include <string.h>

using namespace std;

#define MAX 1123

int slen;
char source[MAX], target[MAX], ans[MAX];
stack <char> s;
string op = string();

void bt(int i, int ansl){
  int j;
  for(j = 0; ansl && j < ansl; j++)
    if(ans[j] != target[j]) return;
  if(ansl == slen){
    for(j = 0; j < op.length(); j++)
      printf("%s%c", j ? " " : "", op[j]);
    printf("\n");
  }
  if(i < slen){
    s.push(source[i]);
    op.push_back('i');
    bt(i+1, ansl);
    op.erase(op.end() - 1);
    s.pop();
  }
  if(!s.empty()){
    ans[ansl] = s.top();
    s.pop();
    op.push_back('o');
    bt(i, ansl+1);
    op.erase(op.end() - 1);
    s.push(ans[ansl]);
  }
}

int main(void){

  while(scanf("%s", source) != EOF){
    scanf("%s", target);
    slen = strlen(source);
    printf("[\n");
    if(slen == strlen(target)) bt(0, 0);
    printf("]\n");
  }


  return 0;
}
