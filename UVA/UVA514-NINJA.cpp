#include <stdio.h>
#include <stack>

using namespace std;

#define MAX 1123

int main(void){
  int i, j, n, train[MAX];
  
  while(scanf("%d", &n), n){
    while(scanf("%d", &train[0]), train[0]){ 
      stack<int> s;
      for(i = 1; i < n; i++) scanf("%d", &train[i]);
      for(j = 0, i = 1; i <= n; i++){
	s.push(i);
	//printf("%d %d\n", s.top(), train[j]);
	while(!s.empty() && s.top() == train[j]){ s.pop(); j++; }
      }
      if(s.empty()) printf("Yes\n");
      else printf("No\n");
    }
    printf("\n");
  }

  return 0;
}
