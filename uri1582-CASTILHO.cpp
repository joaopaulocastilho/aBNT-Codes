#include <stdio.h>

void ordena(int &n1, int &n2, int &n3){
  int aux, maior;
  maior = n1;
  if(maior < n2){
    maior = n2;
    aux = n1;
    n1 = n2;
    n2 = aux;
  }
  if(maior < n3){
    maior = n3;
    aux = n1;
    n1 = n3;
    n3 = aux;
  }
}

int pitagoras(int n1, int n2, int n3){
  n1 *= n1;
  n2 = (n2*n2) + (n3*n3);
  if(n1 == n2) return 1;
  return 0;
}

int mdc(int a, int b){
  if (b == 0) return a;
  return mdc(b, a % b);
}

int main(void){
  int n1, n2, n3;
  while(scanf("%d%d%d", &n1, &n2, &n3) != EOF){
    ordena(n1, n2, n3);
    if(!pitagoras(n1, n2, n3)) printf("tripla\n");
    else if(mdc(n1, mdc(n2, n3)) == 1) printf("tripla pitagorica primitiva\n");
    else printf("tripla pitagorica\n");
  }
  return 0;
}
