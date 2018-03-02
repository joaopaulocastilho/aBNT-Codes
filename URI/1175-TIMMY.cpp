#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
  int v[20];
  for(int i = 0; i < 20; i++){
    scanf("%d", &v[i]);
  }
  for(int i = 0, j = 19; i < j; i++, j--)
    swap(v[i], v[j]);
  for(int i = 0; i < 20; i++)
    printf("N[%d] = %d\n", i, v[i]);
  return 0;
}
