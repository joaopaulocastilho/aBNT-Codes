#include<stdio.h>
int main(){
    int i,x,y;
    unsigned long long fat1,fat2;
    while (scanf("%d %d",&x,&y) != EOF ){
        for(fat1=1,i=1;i<=x;i++) fat1*=i;
        for(fat2=1,i=1;i<=y;i++) fat2*=i;
        printf("%llu\n",fat1+fat2);
    }
    return 0;
}
