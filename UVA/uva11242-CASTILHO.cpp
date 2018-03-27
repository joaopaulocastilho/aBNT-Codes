#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 112
#define EPS 10e-9

typedef vector<double> vd;

int main(void) {
  int f, r, i, j, vf[MAX], vr[MAX];
  double maior;
  while (scanf("%d", &f), f) {
    scanf("%d", &r);
    vd ratio;
    for (i = 0; i < f; i++) scanf("%d", &vf[i]);
    for (i = 0; i < r; i++) scanf("%d", &vr[i]);
    for (i = 0; i < f; i++)
      for (j = 0; j < r; j++)
        ratio.push_back((double)vf[i] / (double)vr[j]);
    sort(ratio.begin(), ratio.end());
    for (maior = 0, i = 1; i < (int)ratio.size(); i++)
      if ((ratio[i] / ratio[i - 1]) - maior > EPS)
        maior = ratio[i] / ratio[i - 1];
    printf("%.2lf\n", maior);
  }
  return 0;
}
