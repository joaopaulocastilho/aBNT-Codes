#include<stdio.h>
int main(){
int m,n,c=1,sum=0;

    while (m!=0 && n!=0){

        scanf("%d %d",&m,&n);
        if (n>m) {sum=n ; n=m ;m=sum ; sum=0 ;}
            if (m!=0 && n!=0) {
                if (c==1){c=n;}
                    while (c<m){
                    sum+=c;
                    printf("%d ",c);
                    c+=1;}
            }
        if(c==m){sum+=c; printf("%d Sum=%d\n",m,sum);}
        c=1;
        sum=0;
    }

return 0;}
