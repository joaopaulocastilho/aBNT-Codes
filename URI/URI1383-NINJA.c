#include <stdio.h>
int main (){
    int i,j,sudoku[9][9],n,inst=1,flag,soma=0,somattl;
    scanf("%d",&n);
    while (n--){
        somattl=0;
        flag=0;
        for(i=0;i<9;i++)
            for(j=0;j<9;j++){
                scanf("%d",&sudoku[i][j]);
            }
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                somattl+=soma+=sudoku[i][j];
            }
            if (soma!= 45) flag++;
            soma=0;
        }

        for(j=0;j<9;j++){
            for(i=0;i<9;i++){
                somattl+=soma+=sudoku[i][j];
            }
            if (soma!= 45) flag++;
            soma=0;


        }
        printf("Instancia %d\n",inst);
        inst++;
        if(flag==0 && somattl== 4050) printf("SIM\n\n");
        else printf("NAO\n\n");
        //printf("%d",somattl);
    }


    return 0;
}
