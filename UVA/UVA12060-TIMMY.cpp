#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int a, int b){ return b == 0 ? a : gcd(b, a % b ); }

int main(void){
  int n, count, sum, num, pint, resto, div, pfracr, pfracd, aux, spacesint, spacesdiv, spacesres;
  int caso = 0;
  while(scanf("%d", &n), n != 0){
    printf("Case %d:\n", ++caso);
    sum = 0;
    count = 0;
    spacesint = 0;
    spacesdiv = spacesres = 1;    
    while(n--){
      scanf("%d", &num);
      sum += num; count++;
    }
    if(sum % count == 0){
      if(sum < 0) printf("- ");
      sum = abs(sum);
      printf("%d\n", sum/count); continue;
    }
    num = abs(sum);
    while(num % count != 0) num--;
    pint = num/count;
    if(sum < 0){ spacesint += 2; }
    if(pint != 0) spacesint++;
    resto = abs(sum) - num;
    div = gcd(resto, count);
    pfracr = resto/div; // parte fracao do resto
    pfracd = count/div; // parte fracao do divisor
    aux = pint;
    while(aux >= 10){ aux = aux/10; spacesint++; }
    aux = pfracd;
    while(aux >= 10){ aux = aux/10; spacesdiv++; }
    aux = pfracr;
    while(aux >= 10){ aux = aux/10; spacesres++; }
    for(int i = 0; i < spacesint + spacesdiv - spacesres; i++)
      printf(" ");
    printf("%d\n", pfracr);
    if(sum < 0) printf("- ");
    if(pint != 0) printf("%d", pint);
    for(int i = 0; i < spacesdiv; i++) printf("-");
    printf("\n");
    for(int i = 0; i < spacesint; i++) printf(" ");
    printf("%d\n", pfracd);
  }
  return 0;
}
