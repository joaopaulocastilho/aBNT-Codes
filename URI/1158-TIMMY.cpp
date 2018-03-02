#include <cstdio>


int main(void){
  int ans, start, it, tc;
  scanf("%d", &tc);
  while(tc--){
    scanf("%d %d", &start, &it);
    if(start % 2 != 0){ ans = start++; it--; }
    else ans = 0;
    for(int i = 0; i < it; start++)
      if(start % 2 != 0){ ans+= start; i++; }
    printf("%d\n", ans);
  }
  return 0;
}
