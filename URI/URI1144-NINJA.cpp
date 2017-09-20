#include<stdio.h>
int main() {
int n,c=1;
    scanf("%d",&n);
        while(n--){
            printf("%d %d %d\n",c,c*c,c*c*c);
            printf("%d %d %d\n",c,c*c+1,c*c*c+1);
            c+=1;
        }


return 0;
}
