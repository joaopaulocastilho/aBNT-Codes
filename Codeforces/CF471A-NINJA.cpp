#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
  int i, j, num, equal, alien = 1;
  vector <int> sticks;
  vector <int> others;
  
  for(i = 0; i < 6; i++){
    scanf("%d", &num);
    sticks.push_back(num);
  }
  sort(sticks.begin(), sticks.end());
  
  for(equal = i = 0; i < 6; i++){
    if(i && sticks[i] == sticks[i-1]){
      equal++;
    }
    else equal = 0;
    if(equal == 3){
      for(j = i; j >= i-3; j--) sticks[j] = -1;
      equal = alien = 0;
    }
  }
  if(alien) printf("Alien\n");
  else{
    for(i = 0; i < 6; i++)
      if(sticks[i] != -1) others.push_back(sticks[i]);
    if(others[0] == others[1]) printf("Elephant\n");
    else printf("Bear\n");
  }
  
  return 0;
}
