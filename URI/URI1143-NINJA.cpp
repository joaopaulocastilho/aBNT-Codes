#include<stdio.h>
int main(){
int n,x=1;
    scanf("%d",&n);
        while (n--){
            printf("%d %d %d\n",x,x*x,x*x*x);
            x+=1;
        }

return 0;
}
