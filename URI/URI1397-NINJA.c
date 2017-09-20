#include<stdio.h>
int main(){
    int n,a,b,j1=0,j2=0;
    scanf("%d",&n);
    while (n!=0){
        while(n--){
            scanf("%d %d",&a,&b);
            if (a>b)j1++;
            else if(a<b)j2++;
        }
        printf("%d %d\n",j1,j2);
        j1=j2=0;
        scanf("%d",&n);
    }
    return 0;
}
