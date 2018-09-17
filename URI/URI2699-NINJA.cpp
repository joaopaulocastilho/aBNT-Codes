#include <bits/stdc++.h>

#define tonum(c) ((c-'0'))

typedef struct{int m, flag;} memo_t;

const int MAX = 1123;

int n, end;
char str[MAX], ans[MAX];
memo_t memo[MAX][MAX];

int expbin(int a, int b, int m){
  int y;
  if(b == 0) return 1;
  if(b & 1) return ((a % m) * expbin(a, b-1, m)) % m;
  y = expbin(a, b >> 1, m);
  return (y * y) % m;
}

int pd(int i, int res){
  int eb, j;
  if(i < 0) return res == 0;
  if(memo[i][res].m != -1) return memo[i][res].m;
  if(str[i] != '?'){
    eb = (((tonum(str[i]))%n) * expbin(10, end-i-1, n)) % n;
    ans[i] = str[i];
    memo[i][res].m = pd(i-1, (eb + res) % n);
    if(i == 0 && memo[i][res].m){//setar flags
      if (ans[0] == -1 || tonum(str[0]) < tonum(ans[0])) memo[0][res].flag = 1;
      else if(ans[0] == str[0]) memo[0][res].flag = 0;
    }
  }
  memo[i][res].m = 0;
  for(j = (i == 0); j <= 9; j++){
    eb = ((j % n) * expbin(10, end-i-1, n)) % n;
    memo[i][res].m |= pd(i-1, (eb + res) % n);
    if(i == 0 && memo[i][res].m){//setar flags
      if (ans[0] == -1 || j < tonum(ans[0])) memo[0][res].flag = 1;
      else if(ans[0] == str[0]) memo[0][res].flag = 0;
    }
    if(memo[i][res].m && memo[i][res].flag == 0 && j < tonum(ans[i])) memo[i][res].flag = 1;
    if(memo[i][res].m && memo[i][res].flag == 1) ans[i] = j + '0';
}
  return memo[i][res].m;
}

int main(void){
  
  scanf("%s %d ", str, &n);
  memset(memo, -1, sizeof(memo));
  memset(ans, -1, sizeof(ans));
  end = strlen(str);
  ans[end] = 0;
  printf("%s\n", pd(end-1, 0) ? ans : "*");
	 
  return 0;
}
