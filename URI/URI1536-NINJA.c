#include<stdio.h>
int main(){
    int N,t1m,t1v,t2m,t2v;
    scanf("%d",&N);
    while (N--){
        scanf("%d x %d",&t1m,&t2v);
        scanf("%d x %d",&t2m,&t1v);
        if (t1m+t1v>t2m+t2v) printf("Time 1\n");
        else if (t1m+t1v<t2m+t2v) printf("Time 2\n");
        else if (t1v>t2v) {printf("Time 1\n");}
        else if (t1v<t2v) {printf("Time 2\n");}
        else printf("Penaltis\n");
    }
    return 0;
}
