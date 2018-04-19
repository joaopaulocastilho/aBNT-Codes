#include <cstdio>
#include <algorithm>

using namespace std;


int main(void){
  int n, m;
  scanf("%d %d", &m, &n);
  if(min(m, n) % 2 == 0) printf("Malvika\n");
  else printf("Akshat\n");
  
  return 0;
}
