#include <stdio.h>
#include <string.h>

#define MAX 2623456
#define MAXC 2000001

int campo[2][MAX], A[MAX], B[MAX], n;

void ft_set(int time, int pos, int val){
  int i;
  for(i = pos; i <= MAXC; i += i & -i)
    campo[time][i] += val;
}

int ft_get(int time, int pos){
  int ret = 0, i;
  for(i = pos; i; i -= i & -i)
    ret += campo[time][i];
  return ret;
}

int impedido(int time, int num){
  if(!time){
    return (ft_get(!time, MAXC) - ft_get(!time, A[num]) < (n) / 11.0);
  }
  return (ft_get(!time, B[num]-1) < (n) / 11.0);
}

int main(void){
  int e, i, imp, num, npos, gol[2];
  char c, time;
  while(scanf("%d %d", &n, &e), n){
    imp = 0;
    memset(campo, 0, sizeof(campo));
    memset(gol, 0, sizeof(gol));
    for(i = 1; i <= n / 2; i++){ scanf("%d", &A[i]); A[i]++; ft_set(0, A[i], 1); }
    for(i = 1; i <= n / 2; i++){ scanf("%d", &B[i]); B[i]++; ft_set(1, B[i], 1); }
    for(i = 0; i < e; i++){
      scanf(" %c", &c);
      switch(c){
      case 'I':
	scanf(" %c%d", &time, &num);
	imp |= impedido(time - 'A', num);
	break;
      case 'M':
	scanf(" %c%d %d", &time, &num, &npos);
	time -= 'A';
	ft_set(time, (time == 0) ? A[num] : B[num], -1);
	ft_set(time, npos + 1, 1);
	if(!time) A[num] = npos + 1;
	else B[num] = npos + 1;
	break;
      case 'P':
	scanf(" %c%d", &time, &num);
	imp |= impedido(time - 'A', num);
	break;
      case 'G':
	scanf(" %c", &time);
        time -= 'A';
	if(!imp) gol[!time]++;
	imp = 0;
	break;
      case 'S':
	imp = 0;
	break;
      }
      //printf("[%d] ", imp);
    }
    printf("%d X %d\n", gol[0], gol[1]);
  }
  return 0;
}
