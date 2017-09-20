#include <stdio.h>
int main(){
    int n,i,num,p=0;
    scanf("%d",&n);
    while (n--){
    scanf("%d",&num);
        for(i=1;i<=num;i++){
            if(num%i==0){p++;}
        }
    if(p>2){printf("%d nao eh primo\n",num);}
    else {printf("%d eh primo\n",num);}
    p=i=0;
    }


    return 0;
}
