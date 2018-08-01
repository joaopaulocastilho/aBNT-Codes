#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int n, pos, pos2, num1, num2;
  vector<int> v;

  while(scanf("%d", &n) != EOF){
    v.push_back(n);
    if(v.size() % 2){
      pos = v.size() / 2;
      nth_element(v.begin(), v.begin() + pos ,v.end());
      printf("%d\n", v[pos]);
    }
    else{
      pos = (v.size()/2); pos2 = (v.size()/2) - 1;
      nth_element(v.begin(), v.begin() + pos ,v.end()); num1 = v[pos];
      nth_element(v.begin(), v.begin() + pos2 ,v.end()); num2 = v[pos2];
      printf("%d\n", (num1+num2)/2);
    }
  }
  return 0;
}
