#include <stdio.h>


int main(void){
    int n, k, kn;

    scanf("%d", &n);
    while(n--){
        scanf("%d", &k);
        while(k--){
            scanf("%d", &kn);
            if(kn == 1) printf("Rolien\n");
            else if(kn == 2) printf("Naej\n");
            else if(kn == 3) printf("Elehcim\n");
            else printf("Odranoel\n");
        }
    }
    return 0;
}
