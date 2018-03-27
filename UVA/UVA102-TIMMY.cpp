#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX 1123
#define INF 112345678

int main(void){
  int m, matrix[MAX][MAX], ans, nans;
  char c;
  while(scanf("%d", &m) != EOF){
    getchar();
    for(int i = 0; i < m; i++){
      for(int j = 0; j < m; j++){
	scanf("%c", &c);
	matrix[i][j] = c - '0';
      }
      getchar();
    }
    nans = 0;
    for(int i = 0; i < m; i++){
      for(int j = 0; j < m; j++){
	if(matrix[i][j] == 1){
	  ans = INF;
	  for(int k = 0; k < m; k++){
	    for(int l = 0; l < m; l++){
	      if(matrix[k][l] == 3){
		ans = min(ans, abs(k - i) + abs(l-j));
	      }
	    }
	  }
	}
	nans = max(nans, ans);
      }
    }
    printf("%d\n", nans);
  }


  return 0;
}
