#include <stdio.h>
#include <string.h>

typedef struct{ int n; char c;}pos_t;

int grid[10][10];
int mov_x[] = {1, 2, 1, 2, -1, -2, -1, -2};
int mov_y[] = {-2, -1, 2, 1, -2, -1, 2, 1};

void marca_grid(pos_t peao){
  int aux = peao.c - 'a' + 1;
  grid[peao.n-1][aux-1] = 1;
  grid[peao.n-1][aux+1] = 1;
}

int valida_pos(pos_t cavalo, int i){
  if(cavalo.n+mov_x[i] > 0 &&
     cavalo.n+mov_x[i] < 9 &&
     cavalo.c+mov_y[i] >= 'a' &&
     cavalo.c+mov_y[i] <= 'h') return 1;
  return 0;
}

int main(void){
  pos_t cavalo, peao[10];
  int i, cont, it=1;
  while(scanf("%d", &cavalo.n), cavalo.n){
    scanf("%c", &cavalo.c);
    cont=0;
    memset(grid, 0, sizeof(grid));
    for(i=0; i<8; i++){
      scanf("\n%d%c", &peao[i].n, &peao[i].c);
      marca_grid(peao[i]);
    }
    getchar();
    for(i=0; i<8; i++)
      if(valida_pos(cavalo, i) &&
	 grid[cavalo.n+mov_x[i]][cavalo.c+mov_y[i]-'a'+1] != 1) cont++;
    printf("Caso de Teste #%d: %d movimento(s).\n", it, cont);
    it++;
  }
  return 0;
}
