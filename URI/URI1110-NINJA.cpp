#include <stdio.h>
#include <queue>

using namespace std;

int main(void){
  int i, n, first;
  queue <int> q;

  while(scanf("%d", &n), n){
    for(first = i = 1; i <= n; i++) q.push(i);
    printf("Discarded cards: ");
    while(q.size() > 1){
      if(first) first = 0;
      else printf(", ");
      printf("%d", q.front());
      q.pop();
      q.push(q.front());
      q.pop();
    }
    printf("\nRemaining card: %d\n", q.front());
    q.pop();
  }
  
  return 0;
}
