//Adhoc
#include <stdio.h>

int main(void){
    int t,c,i,resp = 0;
    scanf("%d",&t);
    for(i = 0; i < 5; i++){
        scanf("%d",&c);
        if(c == t) resp ++;
    }
    printf("%d\n",resp);
    return 0;
}
