#include<stdio.h>
int main(){
    unsigned long long a,b;
    while(scanf("%llu %llu",&a,&b)!=EOF) b>a ? printf("%llu\n",b-a) : printf("%llu\n",a-b);
    return 0;
}
