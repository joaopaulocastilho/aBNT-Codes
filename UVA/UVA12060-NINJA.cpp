#include <stdio.h>
#include <stdlib.h>

#define EPS 10e-9

int numDig(int x){
  int ans = 0;
  while(x){x /= 10; ans++;}
  return ans;
}

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a%b); }

int main(void){
  int a, b, c, i, tmp, sum, n, num, neg, just, risco, caso = 1;

  while(scanf("%d", &n), n){
    a = b = c = -1;
    for(neg = sum = i = 0; i < n; i++){
      scanf("%d", &num);
      sum += num;
    }
    a = abs(sum/n);
    if(double(sum)/n < 0) neg = 1;
    if(sum % n){
      tmp = abs(sum);
      while(tmp % n) tmp--;
      sum = abs(sum) - tmp;
      b = sum; c = n;
      tmp = gcd(b,c);
      b /= tmp; c /= tmp;
    }
    if(c != -1) just = numDig(c);
    if(a != -1 && a != 0) just += numDig(a);
    if(neg) just += 2;
    printf("Case %d:\n", caso++);
    //printf("J = %d\n", just);
    if(b != -1) printf("%*d\n", just, b);
    if(neg) printf("- ");
    if( (a != -1 && a != 0) || b == -1) printf("%d", a);
    risco = just - (a != -1 ? numDig(a) : 0) - (neg ? 2 : 0);
    if(b != -1) for(i = 0; i < risco; i++) printf("-");
    printf("\n");
    if(c != -1) printf("%*d\n", just, c);
  }
  
  return 0;
}
