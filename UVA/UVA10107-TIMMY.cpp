#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
  int num, count = 0, first, second;
  vector<int> v;
  v.clear();
  while(scanf("%d", &num) != EOF){
    count++;
    v.push_back(num);
    nth_element(v.begin(), v.begin()+(count/2), v.end());
    first = v[count/2];
    //for(int i = 0; i < count; i++) printf("%d ", v[i]); printf("\n\n");
    if(count % 2 == 0){
      nth_element(v.begin(), v.begin()+(count/2)-1, v.end());
      second = v[count/2-1];
      printf("%d\n", (first + second) / 2);
      continue;
    }
    printf("%d\n", first);
  }
  return 0;
}
