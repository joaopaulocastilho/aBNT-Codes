#include <stdio.h>

#define MAX 50

typedef struct{
  int nota, hora;

}disc_t;

int main(void){
  int m;
  double sum1, sum2;
  disc_t disc[MAX];

  while(scanf("%d", &m) != EOF){
    sum1 = sum2 = 0;
    for(int i = 0; i < m; i++){
      scanf("%d %d", &disc[i].nota, &disc[i].hora);
      sum1 += disc[i].nota * disc[i].hora;
      sum2 += disc[i].hora;
    }
    printf("%.4lf\n", sum1 / (sum2 * 100));
  }

  return 0;
}
