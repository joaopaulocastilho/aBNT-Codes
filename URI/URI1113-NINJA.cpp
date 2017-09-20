#include<stdio.h>
int main(){
int x,y;

    while (x!=y){

        scanf("%d %d",&x,&y);
        if (y>x) {printf("Crescente\n");}
        else if (x>y) {printf("Decrescente\n");}

    }


return 0;
}
