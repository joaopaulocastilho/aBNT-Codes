#include <cstdio>
#include <vector>

using namespace std;

#define MAX 112345

int main(void){
  int n, m, got, box, num, v[MAX];
  vector<int> need;
  got = 0;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
    scanf("%d", &v[i]);
  }
  while(m--){
    scanf("%d", &num);
    if(num == 2) got++;
    else{
      scanf("%d", &box);
      if(v[box] == 0){ need.push_back(box); got--; }
      else v[box]--;
    }
  }
  for(vector<int>::iterator it = need.begin(); it != need.end(); ++it) printf("%d\n", (*it));
  while(got--) printf("1\n");
  return 0;
}
