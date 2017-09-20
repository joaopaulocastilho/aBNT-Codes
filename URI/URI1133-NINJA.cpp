#include<stdio.h>
int main(){
int x,y;
scanf("%d %d",&x,&y);
    if(y>x){x+=1;
        while(y>x){
            if (x%5==2 || x%5==3){printf("%d\n",x);}
            x+=1;
        }
    }
    else if(x>y){y+=1;
        while(x>y){
            if (y%5==2 || y%5==3){printf("%d\n",y);}
            y+=1;
        }
    }
return 0;
}
