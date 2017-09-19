#include<stdio.h>
#include<algorithm>
using namespace std;

int main(void) {
  int a1, a2, a3, s1, s2, s3;
  scanf("%d %d %d", &a1, &a2, &a3);
  s1 = a2 * 2 + a3 * 4;
  s2 = a1 * 2 + a3 * 2;
  s3 = a1 * 4 + a2 * 2;
  printf("%d\n", min(s1, min(s2, s3)));
  return 0;
}
