#include <stdio.h>

#define MAX 112

int main(void){
  int n, m, l, cm, cl, choosen;
  int mar[MAX][MAX], leo[MAX][MAX];

  while(scanf("%d", &n) != EOF){
    scanf("%d %d", &m, &l);
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++) scanf("%d", &mar[i][j]);

    for(int i = 0; i < l; i++)
      for(int j = 0; j < n; j++) scanf("%d", &leo[i][j]);
    scanf("%d %d", &cm, &cl); cm--; cl--;
    scanf("%d", &choosen); choosen--;
    printf("%s\n", mar[cm][choosen] == leo[cl][choosen] ? "Empate" :
                  (mar[cm][choosen] > leo[cl][choosen] ? "Marcos" : "Leonardo"));
  }

  return 0;
}
