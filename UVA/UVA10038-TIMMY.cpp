#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX 3123

int main(void){
  int n, num, ant, dif, v[MAX], j;
  while(scanf("%d", &n) != EOF){
    memset(v, 0, sizeof(v));
    if(n == 1){
      scanf("%d", &num);
      printf("Jolly\n");
      continue;
    }
    for(int i = 0; i < n; i++){
      scanf("%d", &num);
      if(!i){ ant = num; continue; }
      dif = abs(ant - num);
      v[dif] = 1;
      ant = num;
    }
    j = 1;
    for(int i = 1; i < n; i++) if(!v[i]){ printf("Not jolly\n"); j = 0; break; }
    if(j)
      printf("Jolly\n");
  }
  return 0;
}
