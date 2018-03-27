#include <stdio.h>

#define MAX 17

int main(void) {
  int k, s[MAX], i, j, l, m, n, o, first = 1;
  while (scanf("%d", &k), k) {
    if (first) first = 0;
    else printf("\n");
    for (i = 0; i < k; i++) scanf("%d", &s[i]);
    for (i = 0; i < k - 5; i++)
      for (j = i + 1; j < k - 4; j++)
        for (l = j + 1; l < k - 3; l++)
          for (m = l + 1; m < k - 2; m++)
            for (n = m + 1; n < k - 1; n++)
              for (o = n + 1; o < k; o++)
                printf("%d %d %d %d %d %d\n",
                       s[i], s[j], s[l], s[m], s[n], s[o]);
  }
  return 0;
}
