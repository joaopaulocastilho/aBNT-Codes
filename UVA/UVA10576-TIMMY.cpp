#include <cstdio>
#include <cstring>


#define MAX 112
#define INF 1123456789
int v[MAX], d, s;

int bt(int idx){
  int sum = 0, op1, op2, aux;
  if(idx > 4){
    for(int i = 0; i < 5; i++){
      sum += v[i];
      //printf("%d ", sum);
    }
    if(sum >= 0) return -INF;
    for(int i = 5; i < idx; i++){
      sum -= v[i-5];
      sum += v[i];
      //printf("%d ", sum);
      if(sum >= 0) return -INF;
    }
    //printf("\n");
  }
  if(idx == 12){
    sum = 0;
    for(int i = 0; i < idx; i++)
      sum += v[i];
    return sum;
  }
  else{
    aux = v[idx];
    v[idx] = -d;
    op1 = bt(idx+1);
    v[idx] = s;
    op2 = bt(idx+1);
    v[idx] = aux;
    return (op1 > op2 ? op1 : op2);
  }
}

int main(void){
  int ans;
  while(scanf("%d %d", &s, &d) != EOF){
    memset(v, 0, sizeof(v));
    ans = bt(0);
    if(ans > 0){
      printf("%d\n", ans);
    }
    else printf("Deficit\n");
  }
  return 0;
}
