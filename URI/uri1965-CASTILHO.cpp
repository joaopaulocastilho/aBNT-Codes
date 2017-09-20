#include <stdio.h>

#define ESQ 1
#define DIR 2

typedef long long ll;

int main(void){
  int N, d1, d2, p1, p2, ant, at, pos=0;
  ll d, p, pe, pd, ce=0, cd=0;
  char t;
  scanf("%d %d.%d %d.%d", &N, &d1, &d2, &p1, &p2);
  d=d1*100+d2; p=p1*100+p2;
  scanf("%d", &ant);
  while(--N){
    scanf("%d", &at);
    if(ant<at && pos!=ESQ){ ce++; pos=ESQ; }
    else if(ant>at && pos!=DIR){ cd++; pos=DIR; }  
    ant=at;
  }
  scanf("\n%c", &t);
  if(t=='<'){
    pd = (p-ce*d)/(ce+cd); pe = d+pd;
  }else{
    pe = (p-cd*d)/(ce+cd); pd = d+pe;
  }
  printf("<) %lld R$%lld.%02lld\n(> %lld R$%lld.%02lld\n",
	 ce, pe/100, pe%100, cd, pd/100, pd%100);
  return 0;
}
