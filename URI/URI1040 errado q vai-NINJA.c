#include<stdio.h>
    int main(void){
    double n1,n2,n3,n4,media,exame,media2;
        scanf("%lf %lf %lf %lf %lf",&n1,&n2,&n3,&n4,&exame);
    media = (2*n1 + 3*n2 + 4*n3 + 1*n4)/(2 + 3 + 4 + 1);
        printf("Media: %.1lf\n",media);
    if (media>=7.0)
        {printf("Aluno aprovado.\n");return 0;}
    if (media<5.0)
        {printf("Aluno reprovado.\n");return 0;}
    if (media>=5.0 && media<=6.9)
        printf("Aluno em exame.\n");

        printf("Nota do exame: %.1lf\n" ,exame);
    media2=(exame+media)/2;
    if (media2>=5.0)
        printf("Aluno aprovado.\n");
    else
        printf("Aluno reprovado.\n");
    printf("Media final: %.1lf\n",media2);


    return 0;}
