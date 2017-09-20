#include<stdio.h>
    int main(){
        int a,b,c,d,e,par=0,impar=0,pos=0,neg=0;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        if (a%2==0){par+=1;}
            else{impar+=1;}
        if (b%2==0){par+=1;}
             else{impar+=1;}
        if (c%2==0){par+=1;}
             else{impar+=1;}
        if (d%2==0){par+=1;}
             else{impar+=1;}
        if (e%2==0){par+=1;}
             else{impar+=1;}
        if (a>0) {pos+=1;}
            else if (a!=0) {neg+=1;}
        if (b>0) {pos+=1;}
            else if (b!=0) {neg+=1;}
        if (c>0) {pos+=1;}
           else if (c!=0) {neg+=1;}
        if (d>0) {pos+=1;}
            else if (d!=0) {neg+=1;}
        if (e>0) {pos+=1;}
            else if (e!=0) {neg+=1;}
    printf("%d valor(es) par(es)\n%d valor(es) impar(es)\n%d valor(es) positivo(s)\n%d valor(es) negativo(s)\n",par,impar,pos,neg);
    return 0;}
