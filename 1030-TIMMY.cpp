#include <stdio.h>
#include <string.h>

int josephus(int n, int k);

int main(void){
    int n, k, a, NC, i;
    scanf("%d", &NC);
    for (i=1; i <= NC; i++){
        scanf("%d %d", &n, &k);
        a = josephus(n, k);
        printf("Case %d: %d\n", i, a);
    }
    return 0;
}

int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    return (josephus(n - 1, k) + k-1) % n + 1;
}
