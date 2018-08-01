#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define MAX 5123

char str1[MAX], str2[MAX];
int memo[MAX][MAX], end1, end2;

int lcs(int a, int b){
  int n1, n2;
  if(memo[a][b] != -1) return memo[a][b];
  if(a > end1 || b > end2) return memo[a][b] = 0;
  if(str1[a] == str2[b]) return memo[a][b] = lcs(a+1, b+1) + 1;
  return memo[a][b] = max(lcs(a+1, b), lcs(a, b+1));
  
}

int main(void){
  memset(memo, -1, sizeof(memo));
  scanf("%s ", str1);
  scanf("%s ", str2);
  end1 = strlen(str1);
  end2 = strlen(str2);
  
  printf("%d\n", lcs(0, 0)-1);

  return 0;
}
