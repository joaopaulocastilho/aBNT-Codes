#include <cstdio>

#define MAX 1123456

int main(void){
  int n, a, b, v[MAX], first, count, turn, j;
  char c;
  scanf("%d %d %d", &n, &a, &b);
  for(int i = 0;i < n; i++){
    scanf(" %c", &c);
    v[i] = (c == '*' ? 3 : -1);
  }
  first = 1; count = 0;
  for(j = 0; a > 0 && b > 0 && j < n; j++){
    if(v[j] == -1){
      if(first){
	first = 0;
	turn = (a > b ? 0 : 1);
      }
      if(turn == 0){ a--; count++; v[j] = turn; }
      else { b--; count++; v[j] = turn; }
      turn = (turn + 1) % 2;
    }
    else{
      first = 1;
    }
  }
  if(j != n && (a > 0 || b > 0)){
    int resto = (a != 0 ? 0 : 1);
    for(; j < n && (a > 0 || b > 0); j++){
      if(v[j] == -1){
	if(j == 0){
	  v[j] = resto; if(resto == 0) a--; else b--;
	  count++;
	  continue;
	}
	if((j > 0 && v[j-1] != resto) && (j < n && v[j+1] != resto)){
	  v[j] = resto; if(resto == 0) a--; else b--;
	  count++;
	  continue;
	}
	if(j == n-1 && v[j-1] != resto){
	  v[j] = resto; if(resto == 0) a--; else b--;
	  count++;
	  continue;
	}
      }
    } 
  }
  //for(int i = 0; i < n; i++) printf("%d ", v[i]); printf("\n");
  printf("%d\n", count);
  return 0;
}
