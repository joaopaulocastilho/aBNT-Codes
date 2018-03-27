#include <stdio.h>

#define M 1000000
#define B 2000000000

typedef long long ll;

int main(void) {
  ll ai, bi, ci, di, alfa, beta;
  for (ai = 1; ai <= 2000; ai++) {
    if (ai * ai * ai * ai > B) break;
    for (bi = ai; bi <= 2000 - ai; bi++) {
      if (ai * bi * bi * bi > B) break;
      for (ci = bi; ci <= 2000 - (ai + bi); ci++) {
	if (ai * bi * ci * ci > B) break;
	alfa = ai + bi + ci;
	beta = ai * bi * ci;
	if (beta == M || (alfa * M) % (beta - M)) continue;
        di = (alfa * M) / (beta - M);
	if (ci <= di && alfa + di <= 2000 && beta * di <= B)
	  printf("%.2lf %.2lf %.2lf %.2lf\n",
		 (double)ai/100, (double)bi/100, (double)ci/100, (double)di/100);
      }}}
  return 0;
}
