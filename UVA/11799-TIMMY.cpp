#include <cstdio>

int main(void){
  int n, s, maior;
  
  scanf("%d\n", &n);
  getchar();
  for(int i = 1; i <= n; i++){
    maior = -1;
    scanf("%d", &s);
    if(s > maior) maior = s;
    while(getchar() != '\n'){
      scanf("%d", &s);
      if(s > maior) maior = s; 
    }
    printf("Case %d: %d\n", i, maior);
  }

  return 0;
}
