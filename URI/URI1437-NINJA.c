#include<stdio.h>
int main(){
    int n,i;
    char x='N',c[2000];
    scanf("%d",&n);
    while (n!=0){
        scanf("%s",&c);
        for(i=0;i<n;i++){
            switch (c[i]){
            case 'D':
                if(x=='N')  x='L';
                else if(x=='L') x='S';
                else if(x=='S') x='O';
                else if(x=='O') x='N';
            break;
            case 'E':
                if(x=='N')  x='O';
                else if(x=='L') x='N';
                else if(x=='S') x='L';
                else if(x=='O') x='S';
            break;
            }
        }
        printf("%c\n",x);
        x='N';
        scanf("%d",&n);
    }
    return 0;
}
