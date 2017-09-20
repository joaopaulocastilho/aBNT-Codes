#include<stdio.h>
int main(){
    double s=1,n=3,p=2;
        while (n!=39){
            s+=n/p;
            n+=2;
            p*=2;
        }
    printf("%.2lf\n",s);
    return 0;
}
