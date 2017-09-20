#include <cstdio>
#include <queue>

using namespace std;

#define MAX 112345

int main(void){
  int n, k, v[MAX], ans = 0;
  priority_queue< int, vector<int>, less<int> > pq; 
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }
  for(int j = n-1; j >= 0; j--){
    pq.push(v[j]);
    if(j % (k+1) == k) pq.pop();
  }
  while(!pq.empty()){
    ans += pq.top();
    pq.pop();
  }
  printf("%d\n", ans);

  return 0;
}
