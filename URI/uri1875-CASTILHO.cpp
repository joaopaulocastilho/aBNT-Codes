#include <stdio.h>
#include <string.h>

int qtd_gol(char m, char s){
  if(m == 'R'){
    if(s == 'G') return 2;
    return 1;
  }else if(m == 'G'){
    if(s == 'B') return 2;
    return 1;
  }else{
    if(s == 'R') return 2;
    return 1;
  }
  return 0;
}

int pos(char m){
  if(m == 'R') return 0;
  if(m == 'G') return 1;
  return 2;
}

int vencedor(int v[3]){
  if(v[0] == v[1] && v[1] == v[2]) return -1;
  if((v[0] == v[1] && v[0] > v[2]) ||
     (v[1] == v[2] && v[1] > v[0]) ||
     (v[0] == v[2] && v[0] > v[1])) return 0;
  if(v[0] > v[1] && v[0] > v[2]) return 1;
  if(v[1] > v[0] && v[1] > v[2]) return 2;
  return 3;
}

int main(void){
  int c, p, gols[3];
  char m, s;
  scanf("%d", &c);
  while(c--){
    scanf("%d", &p);
    memset(gols, 0, sizeof(gols));
    getchar();
    while(p--){
      scanf("%c %c\n", &m, &s);
      gols[pos(m)] += qtd_gol(m, s);
    }
    if(vencedor(gols) == 1) printf("red\n");
    else if(vencedor(gols) == 2) printf("green\n");
    else if(vencedor(gols) == 3) printf("blue\n");
    else if(!vencedor(gols)) printf("empate\n");
    else printf("trempate\n");
  }
  return 0;
}
