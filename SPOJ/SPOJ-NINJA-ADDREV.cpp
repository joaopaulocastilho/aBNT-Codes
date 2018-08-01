#include <stdio.h>

#define MAX 51

int rev(int x){
  int i, ans, mult, v[MAX];

  for(i = 0; x; i++){
    v[i] = x % 10;
    x /= 10;
  }
  for(i--, mult = 1, ans =  0; i >= 0; i--, mult *= 10)
    ans += v[i] * mult;
  return ans;
}

int main(void){
  int a, b, t;

  scanf("%d", &t);
  while(t--){
    scanf("%d %d", &a, &b);
    //printf("%d\n", rev(a));
    printf("%d\n", rev(rev(a) + rev(b)));
  }
  return 0;
}
