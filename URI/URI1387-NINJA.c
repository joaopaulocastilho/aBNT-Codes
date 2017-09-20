#include<stdio.h>
int main(){
    int L,R;
    do  {scanf("%d %d",&L,&R);
        if(L!=0 && R!=0) printf("%d\n",L+R);
    }while(L!=0 || R!=0);
    return 0;
}
