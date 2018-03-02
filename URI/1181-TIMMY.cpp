#Include <cstdio>

#define MAX 12

int main(void){
  int linha;
  double matriz[MAX][MAX];
  char t;
  scanf("%d", &linha);
  scanf(" %c", &t);
  printf("%c", t);
  for(int i = 0; i < 12; i++){
    for(int j = 0; j < 12; j++){
      scanf("%lf", &matriz[i][j]);
    }
  }
  double ans = 0;
  for(int i = 0; i < 12; i++){
    ans += matriz[linha][i];
  }
  if(t == 'M') ans = ans / 12;
  printf("%.1lf\n", ans);
  
  return 0;
}
