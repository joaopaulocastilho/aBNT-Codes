#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct { int st, y; }dragon_t;

int cmp(dragon_t a, dragon_t b) {
  if (a.st == b.st) return a.y < b.y;
  return a.st < b.st;
}

int main(void) {
  int s, n, resp, i;
  scanf("%d %d", &s, &n);
  vector<dragon_t>dra(n);
  for (i = 0; i < n; i++) scanf("%d %d", &dra[i].st, &dra[i].y);
  //for (i = 0; i < n; i++) printf("ST = %d B = %d\n", dra[i].st, dra[i].y);
  sort(dra.begin(), dra.end(), cmp);
  //printf("\n\n\nAFTER\n");
  //for (i = 0; i < n; i++) printf("ST = %d B = %d\n", dra[i].st, dra[i].y);
  for (i = 0, resp = 1; resp && i < n; i++) {
    resp &= (s > dra[i].st);
    s += dra[i].y;
  }
  printf("%s\n", resp ? "YES" : "NO");
  return 0;
}
