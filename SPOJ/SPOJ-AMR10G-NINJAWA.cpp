#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int t, i, n, k, h;
  vector <int> kids;
  
  scanf("%d", &t);
  while(t--){
    kids.clear();
    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++){
      scanf("%d", &h);
      kids.push_back(h);
    }
    sort(kids.begin(), kids.end());
    printf("%d\n", kids[kids.size()-1] - kids[kids.size()-k]);

  }

  return 0;
}
