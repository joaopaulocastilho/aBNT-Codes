#include<stdio.h>
#include<math.h>
#define ull unsigned long long
int main(){
    ull trigo=0,gramas=0;
    int n,i,quad;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&quad);
        for(i=0;i<quad;i++){
            gramas += pow(2,i)/12;
        }
        printf("%llu kg\n",gramas/1000 );
        gramas=0;
    }
    return 0;
}
