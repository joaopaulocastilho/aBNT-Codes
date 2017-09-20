#include <stdio.h>
#include <map>
#include <string.h>

#define MAX 112

using namespace std;

int main(void){
  int t, total, qtd;
  char alimento[MAX];

  map <string, int> food;
  food["suco de laranja"] = 120;
  food["morango fresco"] = 85;
  food["mamao"] = 85;
  food["goiaba vermelha"] = 70;
  food["manga"] = 56;
  food["laranja"] = 50;
  food["brocolis"] = 34;

  while(scanf("%d", &t), t){
    total = 0;
    while(t--){
      scanf("%d ", &qtd);
      fgets(alimento, MAX, stdin);
      alimento[strlen(alimento) - 1] = '\0';
      total += qtd * food[alimento];
    }
    if(total > 130) printf("Menos %d mg\n", total - 130);
    else if(total < 110) printf("Mais %d mg\n", 110 - total);
    else printf("%d mg\n", total);
  }

  return 0;
}
