#include <cstdio>

int w[MAX], h[MAX];

int pd(int i, int n, int tw, int th){
  if(i > n) return S = -INF;
  if( n) return S = 0;
  return(max(pd(i+1, n, tw + w[i], th+h[i]) + 1, pd(i+1)) )

}

int main(void){
  scanf("%d %d %d", n, w[0], h[0]);
  for(i = 1; i <= n; i++){
    scanf("%d %d", w[i], h[i]);
  }
  pd(0);
  return 0;
}
