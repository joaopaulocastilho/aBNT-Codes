#include<stdio.h>
int main(){
    int i,cpf[20],soma=0,valido=1,b1=0,b2=0,b2c=9;
    char c;
    while(scanf("%c",&c) != EOF){
        for(i=1;i<=11;){
            if(c!='.' && c!='-' ){
                cpf[i]=(int)c-'0';
                soma+=cpf[i];
                if (i<=9) b1+=cpf[i]*i;
                if (i<=9) {b2+=cpf[i]*b2c; b2c--;}
                i++;
            }
            scanf("%c",&c);
        }
        //for(i=1;i<=11;i++) printf("%d ",cpf[i]);
        b1=b1%11; if (b1==10)b1=0;
        b2=b2%11; if (b2==10)b2=0;
        //printf("%d %d",b1,b2);

        if (cpf[10]!=b1 || cpf[11]!=b2) valido=0;

        valido == 1 ? printf("CPF valido\n") : printf("CPF invalido\n");
        soma=b1=b2=0;
        b2c=9;
        valido=1;
    }
    return 0;
}
