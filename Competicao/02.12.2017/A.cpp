#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAXC 5123

int main(void){
  int n, var;
  vector< int > arr(MAXC, 0);
  vector<int> printv;
  scanf("%d", &n);
  for(int i = 1; i <= 2*n; i++){
    scanf("%d", &var);
    if(arr[var] != 0){
      printv.push_back(i);
      printv.push_back(arr[var]);
      arr[var] = 0;
    }
    else
      arr[var] = i;
  }
  for(int i = 1; i <= 2 * n; i++)
    if(arr[i] != 0){ printf("-1\n"); return 0; }
  for(int i = 0; i < (int) printv.size(); i+= 2)
    printf("%d %d\n", printv[i], printv[i+1]);
  return 0;
}
