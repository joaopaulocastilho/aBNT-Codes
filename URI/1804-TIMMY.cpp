#include <cstdio>
#include <cstring>
#define MAX 112345


int bit[MAX], bug[MAX], n;

void put(int x, int val){
  for(; x <= n; x+= x&-x)
    bit[x] += val;
}

void update(int x, int val){
  for(; x <= n; x += x&-x){
    bit[x] -= val;
  }
}
  
int query(int x){
  int sum = 0;
  for(; x > 0; x -= x & -x){
    sum += bit[x];
  }
  return sum;
}


int main(void){
  int p, i = 1, aux, v;
  char c;
  memset(bit, 0, sizeof(bit));
  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    scanf("%d", &p);
    put(i, p);
    bug[i] = p;
  }
  while(scanf(" %c %d", &c, &v) != EOF){
    switch(c){
    case 'a':{
      update(v, bug[v]);
      bug[v] = 0;
      break;
    }
    case '?':{
      printf("%d\n", (query(v)-bug[v]));
      break;
    }
    }
  }
  return 0;
}
