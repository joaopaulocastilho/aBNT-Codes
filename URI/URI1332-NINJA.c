#include<stdio.h>
#include<string.h>
int main(){
    int n,n1=0,n2=0,n3=0,w;
    char s[10];
    //memset
    scanf("%d",&n);
    while (n--){
        scanf("%s",&s);
        if (strlen(s)<5){
            if(s[0]=='o') n1++;
            if(s[1]=='n') n1++;
            if(s[2]=='e') n1++;
            if(s[0]=='t') n2++;
            if(s[1]=='w') n2++;
            if(s[2]=='o') n2++;
        }
        else{
        if(s[0]=='t') n3++;
        if(s[1]=='h') n3++;
        if(s[2]=='r') n3++;
        if(s[3]=='e') n3++;
        if(s[4]=='e') n3++;
        }
        //printf("one:%d two:%d three:%d   ",n1,n2,n3);
        if (n2>n1 && n2>n3) printf("2\n");
        else if (n3>n1 && n3>n2) printf("3\n");
        else if (n1>n2 && n1>n3) printf("1\n");

        n1=n2=0;
        n3=0;
    }

    return 0;
}
