#include <stdio.h>

using namespace std;

int main(void) {
    int n, m, tem, i;
    scanf("%d %d", &n, &m);
    for (tem = n, i = 1; tem; i++) {
        tem--;
        tem += (i % m == 0);
    }
    printf("%d\n", i - 1);
    return 0;
}



