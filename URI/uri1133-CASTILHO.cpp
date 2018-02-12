#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
    int a, b, i;
    scanf("%d %d", &a, &b);
    if (b < a) swap(a, b);
    for(i = a + 1; i < b; i++)
      if(i % 5== 2 || i % 5 == 3) printf("%d\n", i);
    return 0;
}
