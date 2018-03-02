#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int n, num, count = 0, vcount = 0;
  vector<int> pass;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &num);
    pass.push_back(num);
    vcount++;
  }
  sort(pass.begin(), pass.end());
  for(int i = 0, j = vcount-1; i <= j; j--){
    if(pass[j] < 4)
      while(pass[j] + pass[i] <= 4 && i < j){
	pass[j] += pass[i++];
      }
    count++;
  }
  printf("%d\n", count);
  return 0;
}
