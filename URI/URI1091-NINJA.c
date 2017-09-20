#include<stdio.h>
int main(){
    int k=1,n,m,x,y;
    scanf("%d",&k);
    while(k!=0){
        scanf("%d %d",&n,&m);
        while (k--){
            scanf("%d %d",&x,&y);
            if (x>n && y>m) printf("NE\n");
            else if(x>n && y<m) printf("SE\n");
            else if(x<n && y>m) printf("NO\n");
            else if(x<n && y<m) printf("SO\n");
            else printf("divisa\n");
        }
    scanf("%d",&k);
    }
    return 0;
}
