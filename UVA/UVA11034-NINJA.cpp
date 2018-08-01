#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int main(void){
  int t, l, m, num;
  char dir[12];

  scanf("%d", &t);
  while(t--){
    int ferry = 0, pos = 0, ans = 0, side = 0;
    queue<int> sides[2];
    sides[0] = queue<int>();
    sides[1] = queue<int>();
    scanf("%d %d", &l, &m);
    while(m--){
      scanf("%d %s ", &num, dir);
      if(!strcmp("left", dir)) sides[0].push(num);
      else sides[1].push(num);
    }
    while(!sides[0].empty() || !sides[1].empty()){
      ferry = 0;
      while(!sides[side].empty() && sides[side].front() + ferry <= l * 100){
	ferry += sides[side].front();
	sides[side].pop();
      }
      side ^= 1;
      ans++;
    }
    printf("%d\n", ans);
  }

  return 0;
}
