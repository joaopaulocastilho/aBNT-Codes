#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXF 112
#define MAXC 1123

int c, f, frase[MAXF][5], memo[MAXF][MAXC];

int pd(int i, int car){
  if(memo[i][car] != -1) return memo[i][car];
  if(i >= f) return 0;
  if(car + frase[i][0] > c) return memo[i][car] = pd(i+1, car);
  return memo[i][car] = max((pd(i+1, car + frase[i][0]) + frase[i][1]), pd(i+1, car)); 
}


int main(void){
  int ans, count = 0;
  while(scanf("%d %d", &c, &f), c != 0 || f != 0){
    memset(memo, -1, sizeof(memo));
    count++;
    for(int i = 0; i < f; i++){
      scanf("%d %d", &frase[i][0], &frase[i][1]);
    }
    ans = pd(0, 0);
    printf("Teste %d\n%d\n\n", count,  ans);
  }
  return 0;
}
