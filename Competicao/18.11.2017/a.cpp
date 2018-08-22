#include <cstdio>
#include <queue>

using namespace std;

int main(void){
  int n, anterior, a;
  scanf("%d", &n);
  anterior = n+1;
  priority_queue< int, vector<int>, less<int> > pq;
  while(n--){
    scanf("%d", &a);
    if(a == (anterior - 1)){
      anterior = a;
      printf("%d", a);
      while(!pq.empty() && pq.top() == (anterior-1)){
	printf(" %d", pq.top());
	anterior = pq.top();
	pq.pop();
      }
      printf("\n");
    }
    else{
      (pq.push(a));
      printf("\n");
    }
  }
  return 0;
}
