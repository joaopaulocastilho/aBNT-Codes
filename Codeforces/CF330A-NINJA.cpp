#include <stdio.h>
#include <string.h>

#define MAX 21

int main(void){
  int r, c, i, j, ans, cake[MAX][MAX], row[MAX], col[MAX];
  char ch;

  memset(col, 0, sizeof(col));
  memset(row, 0, sizeof(row));
  scanf("%d %d ", &r, &c);
  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++){
      scanf("%c", &ch);
      cake[i][j] = ch == '.' ? 1 : -1;
      if(ch == 'S') row[i] = col[j] = 1;
    }
    getchar();
  }
  
  for(ans = i = 0; i < r; i++){
    if(row[i]) continue;
    for(j = 0; j < c; j++){
      ans += cake[i][j];
      cake[i][j] = 0;
    }
  }
  
  /*
    for(i = 0; i < r; i++){
    for(j = 0; j < c; j++) printf("%d", cake[i][j]);
    printf("\n");
    }
  printf("%d\n", ans);
  */
  
  for(j = 0; j < c; j++){
    if(col[j]) continue;
    for(i = 0; i < r; i++){
      ans += cake[i][j];
      cake[i][j] = 0;
    }
  }
  /*
  for(i = 0; i < r; i++){
    for(j = 0; j < c; j++) printf("%d", cake[i][j]);
      printf("\n");
  }
  */
  printf("%d\n", ans);
}
