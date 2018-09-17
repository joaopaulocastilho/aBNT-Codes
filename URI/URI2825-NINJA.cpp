#include <bits/stdc++.h>

const int MAXQ = 1123;
const int MAXC = 112;
const int INF = 1123456789;

using namespace std;

int memo[MAXC][MAXC];
char dic[MAXQ][MAXC];

int edit_dist(char s[], char t[]){
  int i, j, n = strlen(s), m = strlen(t);
  for(i = 0; i <= max(n, m); i++) memo[0][i] = memo[i][0] = i;
  for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++)
      if(s[i-1] == t[j-1]) memo[i][j] = memo[i-1][j-1];
      else memo[i][j] = min(memo[i-1][j], min(memo[i][j-1], memo[i-1][j-1])) + 1;
  return memo[n][m];
}

int main(void){
  int q, c, i, j, res, ans, small;
  char word[MAXC];

  
  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf(" %s", dic[i]);
  scanf("%d", &c);
  for(i = 0; i < c; i++){
    scanf(" %s", word);
    for(small = INF, j = 0; j < q; j++)
      if((res = edit_dist(word, dic[j])) < small){ small = res; ans = j; }
      
    if(i) printf(" ");
    printf("%s", dic[ans]);
  }
  printf("\n");
  
  return 0;
}
