#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 11234
#define MAXX 112345

int main(void){
  int acards[MAX], bcards[MAX], ahave[MAXX], bhave[MAXX];
  int a, b, i, ansa, ansb;

  while(scanf("%d %d", &a, &b), a || b){
    memset(ahave, 0, sizeof(ahave));
    memset(bhave, 0, sizeof(bhave));
    ansa = ansb = 0;
    for(i = 0; i < a; i++){
      scanf("%d", &acards[i]);
      ahave[acards[i]] = 1;
      if(i && acards[i] == acards[i-1]){ i--; a--; }
    }
    for(i = 0; i < b; i++){
      scanf("%d", &bcards[i]);
      bhave[bcards[i]] = 1;
      if(i && bcards[i] == bcards[i-1]){ i--; b--; }
    }
    for(i = 0; i < b || i < a; i++){
      if(i < a && !bhave[acards[i]]) ansa++;
      if(i < b && !ahave[bcards[i]]) ansb++;
      //printf("%d | %d\n", i < a ? acards[i] : -1, i < b ? bcards[i] : -1);
    }
    printf("%d\n", min(ansa, ansb));
  }

  return 0;
}
