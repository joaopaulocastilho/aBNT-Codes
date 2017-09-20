#include<stdio.h>
int main()  {
    int x,y,c,d,sum=0;
    scanf("%d %d",&x,&y);
    if (x>y){c=y;d=x;}
    else {c=x;d=y;}
            while (c<d){
                    if(c==x || c==y){c+=1;}
                if(c%2==0){c+=1;}
                sum+=c;
                c+=2;
            }
       printf("%d\n",sum);



    return 0;}
