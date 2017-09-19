#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 1123

int b2d[MAX][MAX];
int x, y, n;

void setbit2d(int x1 , int y1 , int val){
  int i, j;
  for(i = x1; i <= x; i += i & (-i))
    for (j = y1; j <= y; j += j & (-j))
      b2d[i][j] += val;
}

int getbit2d(int x1, int y1){
  int i, j, ret = 0;
  for(i = x1; i; i -= i & (-i))
    for (j = y1; j; j -= j & (-j))
      ret += b2d[i][j];
  return ret;
}

void altera(int &x1, int &y1, int &x2, int &y2){
  int auxx1 = x1, auxx2 = x2, auxy1 = y1, auxy2 = y2;
  x1 = min(auxx1, auxx2);
  x2 = max(auxx1, auxx2);
  y1 = min(auxy1, auxy2);
  y2 = max(auxy1, auxy2);
  x1++; y1++; x2++; y2++;
}

int getP(int x1, int y1, int x2, int y2){
  return getbit2d(x2, y2) - getbit2d(x1 - 1, y2) - getbit2d(x2, y1 - 1) +
    getbit2d(x1 - 1, y1 - 1);
}

int main(void){
  int q, x1, y1, x2, y2, p;
  char r;
  while(scanf("%d %d %d", &x, &y, &p), x){
    memset(b2d, 0, sizeof(b2d));
    scanf("%d", &q);
    while(q--){
      scanf(" %c", &r);
      switch(r){
      case 'A':
	scanf("%d %d %d", &n, &x1, &y1); x1++; y1++;
	setbit2d(x1, y1, n);
	break;
      case 'P':
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	altera(x1, y1, x2, y2);
	printf("%d\n", getP(x1, y1, x2, y2) * p);
	break;
      }}
    printf("\n");
  }
  return 0;
}
