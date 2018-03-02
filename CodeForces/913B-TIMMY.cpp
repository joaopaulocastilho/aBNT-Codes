#include <cstdio>

#define MAX 11234

int main(void){
  int vertex, pai[MAX], count[MAX], value, folha[MAX];
  scanf("%d", &vertex);
  folha[1] = 0;
  for(int i = 2; i <= vertex; i++){
    folha[i] = 1;
    scanf("%d", &value);
    pai[i] = value;
    count[value]++;
    if(folha[value] == 1){ count[pai[value]]--; folha[value] = 0; }
  }
  for(int i = 1; i <= vertex; i++)
    if(!folha[i])
      if(count[i] < 3){ printf("No\n"); return 0; }
  printf("Yes\n");
  return 0;
}
