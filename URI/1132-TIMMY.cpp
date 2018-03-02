#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
  int v1, v2, count = 0;
  scanf("%d %d", &v1, &v2);
  if(v1 > v2) swap(v1, v2);
  for(int i = v1; i <= v2; i++)
    if(i % 13 != 0) count += i;
  printf("%d\n", count);
  return 0;
}
