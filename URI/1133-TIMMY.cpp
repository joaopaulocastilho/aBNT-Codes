#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
  int v1, v2, count = 0;
  scanf("%d %d", &v1, &v2);
  if(v1 > v2) swap(v1, v2);
  for(int i = v1+1; i < v2; i++)
    if(i % 5 == 2 || i % 5 == 3)
      printf("%d\n", i);
  return 0;
}
