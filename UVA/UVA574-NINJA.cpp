#include <stdio.h>
#include <set>
#include <vector>

using namespace std;

#define MAX 21

typedef vector<int> vi;

int t, n, sol, nums[MAX];
set<vi> s;
vi curr;

void bt(int sum, int i, int j){
  int k;

  //printf("%d -> ", sum); for(k = 0; k < j; k++) printf("%d ", curr[k]); printf("\n");
  
  if(sum == t){
    if(s.find(curr) != s.end()) return;
    s.insert(curr);
    sol = 1;
    for(k = 0; k < j; k++)
      printf("%s%d", k ? "+" : "", curr[k]);
    printf("\n");
    return;
  }
  if(i == n || sum > t) return;
  curr.push_back(nums[i]);
  bt(sum + nums[i], i+1, j+1);
  curr.erase(curr.begin() + curr.size()-1);
  bt(sum, i+1, j);
}

int main(void){
  int i;
  
  while(scanf("%d", &t), t){
    scanf("%d", &n);
    for(sol = i = 0; i < n; i++) scanf("%d", &nums[i]);
    printf("Sums of %d:\n", t);
    bt(0, 0, 0);
    if(!sol) printf("NONE\n");
  }
  
  return 0;
}
