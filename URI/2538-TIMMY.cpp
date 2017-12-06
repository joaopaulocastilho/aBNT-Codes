#include <cstdio>
#include <cstring>

#define MAX 212345

int bit[MAX], ip, resp;

void update(int pc){
  for(; pc <= MAX; pc += (pc & -pc)) 
    bit[pc] += 1;
}

/*
void query(int pc, int na){
  int sum = 0, sum2 = 0, aux;
  for(aux = pc + ip; aux > 0; aux -= aux & -aux)
    sum += bit[aux];
  for(aux = ((pc - ip) <= 0 ? 1 : (pc - ip - 1)); aux > 0; aux -= aux & -aux)
    sum2 += bit[aux];
  if((sum - sum2) <= na){
    resp++;
    update(pc);
  }
}
*/

int find(int pc){
  int sum = 0;
  for(; pc > 0;( pc -= pc & -pc))
    sum += bit[pc];
  return sum;
}

int main(void){
  int m, pc, na, ans, l, r;
  while(scanf("%d %d", &ip, &m) != EOF){
    memset(bit, 0, sizeof(bit)); resp = 0;
    while(m--){
      scanf("%d %d", &pc, &na);
      l = pc + ip;
      r = (pc - ip <= 0 ? 1 : (pc-ip));
      ans = find(l) - find(r - 1);
      if(ans <= na){
	update(pc);
	resp++;
      }      
    }
    printf("%d\n", resp);
  }
  return 0;
}
