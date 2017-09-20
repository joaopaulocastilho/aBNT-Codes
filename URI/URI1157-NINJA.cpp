#include<stdio.h>
int main(){
int n,c=1;
    scanf("%d",&n);

        while(c<=n){
            if (n%c==0){printf("%d\n",c);}
           c+=1;
        }


return 0;
}
