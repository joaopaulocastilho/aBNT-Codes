#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
  int n, l, r, lop, rop;

  lop = rop = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d %d", &l, &r);
    lop += l; rop += r;
  }
  printf("%d\n", min(n - lop, lop) + min(n -rop, rop));
  
  return 0;
}
