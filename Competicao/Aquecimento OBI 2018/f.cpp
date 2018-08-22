#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#define MAX 1123
#define MAXA -1

int b2d[MAX][MAX], bc2d[MAX][MAX], bm2d[MAX][MAX];
int x, y;

void setbit2d(int x1, int y1, int val){
  int i, j;
  for(i = x1; i <= x; i += i & (-i))
    for(j = y1; j <= y; j+= j & (-j))
      b2d[i][j] += val;
}

void setbitc2d(int x1, int y1, int val){
  int i, j;
  for(i = x1; i <=x; i += i & -i)
    for(j = y1; j <= y; j+= j & -j)
      bc2d[i][j] += val;
}

void setbitm2d(int x1, int y1, int val){
  int i, j;
  for(i = x1; i <=x; i += i & -i)
    for(j = y1; j <= y; j+= j & -j)
      bm2d[i][j] += val;
}

int getbit2d(int x1, int y1){
  int i, j, ret = 0;
  for(i = x1; i; i -= i & (-i))
    for (j = y1; j; j -= j & (-j))
      ret += b2d[i][j];
  return ret;
}

int getbitc2d(int x1, int y1){
  int i, j, ret = 0;
  for(i = x1; i; i -= i & (-i))
    for (j = y1; j; j -= j & (-j))
      ret += bc2d[i][j];
  return ret;
}

int getbitm2d(int x1, int y1){
  int i, j, ret = 0;
  for(i = x1; i; i -= i & (-i))
    for (j = y1; j; j -= j & (-j))
      ret += bm2d[i][j];
  return ret;
}

int getP(int x1, int y1, int x2, int y2){
  return getbit2d(x2, y2) - getbit2d(x1 - 1, y2) - getbit2d(x2, y1 - 1) +
    getbit2d(x1 - 1, y1 - 1);
}

int getPc(int x1, int y1, int x2, int y2){
  return getbitc2d(x2, y2) - getbitc2d(x1 - 1, y2) - getbitc2d(x2, y1 - 1) +
    getbitc2d(x1 - 1, y1 - 1);
}

int getPm(int x1, int y1, int x2, int y2){
  return getbitm2d(x2, y2) - getbitm2d(x1 - 1, y2) - getbitm2d(x2, y1 - 1) +
    getbitm2d(x1 - 1, y1 - 1);
}

int pvalido(int i, int j){
  if(i <= x && j <= y) return 1;
  return 0;
}

int main(void){
  int ans = MAXA;
  string linha;
  cin >> x >> y;
  memset(b2d, 0, sizeof(b2d));
  memset(bm2d, 0, sizeof(bm2d));
  memset(bc2d, 0, sizeof(bc2d));
  for(int p = 1; p <= x; p++){
    cin >> linha;
    for(int q = 1; q <= y; q++){
      if(linha[q] == 'C'){
	setbit2d(p, q, 12);
	setbitc2d(p, q, 1);
      }
      else{ setbit2d(p, q, 25); setbitm2d(p, q, 1); }
    }
  }
  int f; cin >> f;
  f--;
  for(int i = 1; i <= x-f; i++){
    for(int j = 1; j <= y-f; j++){
      if(pvalido(i+f, j+f) == 1){
	if(getPc(i, j, i+f, j+f) > 0 && getPm(i, j, i+f, j+f) > 0){
	  ans = max(ans, getP(i, j, i+f, j+f));
	}
      }
    }
  }
  cout << ans << endl;
  return 0;
}
