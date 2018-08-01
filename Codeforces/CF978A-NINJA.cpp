#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 1123

int main(void){
  int i, n, num, check[MAX];
  vector<int> v;
  
  memset(check, 0, sizeof(check));
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &num);
    v.push_back(num);
  }

  reverse(v.begin(), v.end());
  for(i = 0; i < v.size(); i++){
    if(check[v[i]]) {v.erase(v.begin()+ i); i--;}
    else check[v[i]] = 1;
  }
  reverse(v.begin(), v.end());
  printf("%d\n", v.size());
  for(i = 0; i < v.size(); i++){
    if(i) printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  
  return 0;
}
