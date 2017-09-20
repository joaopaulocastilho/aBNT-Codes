#include <stdio.h>

int main(void){
    int n, a, c;
    char b;

    scanf("%d", &n);
    while(n--){
        scanf("%d%c%d", &a, &b, &c);
        if(a == c) printf("%d\n", (a * c));
        else if(b >= 'a' && b <= 'z') printf("%d\n", (a + c));
        else printf("%d\n", (c-a));
    }
    return 0;
}
