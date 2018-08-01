#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 112345

typedef struct{
  int start, end;
}seq_t;

int difDigs(int x, int y){
  /*int ans = 0;

  while(x%10 != y%10){
    ans++;
    x /= 10; y /= 10;
  }
  return ans; */
  int end1, end2, i, j, eq;
  char numx[MAX], numy[MAX];
  //printf("\n%d %d\n", x, y);
  for(i = 0; x; i++, x /= 10) numx[i] = (x%10) + '0';
  for(j = 0; y; j++, y /= 10) numy[j] = (y%10) + '0';
  numx[i] = numy[j] = 0;

  end1 = strlen(numx); end2 = strlen(numy);
  for(eq = 0, i = end1, j = end2; i >= 0 && j >= 0; i--, j--, eq++)
    if(numx[i] != numy[j]) break;
  eq--;
  
  //printf("\n%s %s\n", numx, numy);
  //printf("max %d eq %d\n", max(end1, end2), eq);
  return max(end1, end2) - eq;  
}

int numDig(int x){
  int ans = 0;
  while(x){ x /= 10; ans++; }
  return ans;
}

int lastDig(int num, int qtd){
  int mult, i, ans = 0;
  for(mult = 1, i = 0; i < qtd; i++, mult *= 10){
    ans += (num%10) * mult;
    num /= 10;
  }
  return ans;
}

int main(void){
  int i, k, n, num, prev, differentDigs, caso = 1;
  seq_t seqs[MAX];
  
  while(scanf("%d", &n), n){
    prev = -1; k = 0;
    while(n--){
      scanf("%d", &num);
      if(prev == -1) seqs[k].start = num;
      else if(num != prev+1){
	seqs[k++].end = prev;
	seqs[k].start = num;
      }
      prev = num;
    }
    seqs[k++].end = prev;
    printf("Case %d:\n", caso++);
    for(i = 0; i < k; i++){
      printf("0%d", seqs[i].start);
      if(seqs[i].start != seqs[i].end){
	differentDigs = difDigs(seqs[i].start, seqs[i].end);
	//printf("\n%d\n", differentDigs);
	printf("-%d", lastDig(seqs[i].end, differentDigs));
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}
