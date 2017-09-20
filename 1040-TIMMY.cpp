#include <stdio.h>


int main(void){
   float n1, n2, n3, n4, media, exame;
   scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
   media = n1 * 0.2 + n2 * 0.3 + n3 * 0.4 + n4 * 0.1;
   printf("Media: %.1f\n", media);
   if(media >= 7) printf("Aluno aprovado.\n");
   if(media >= 5 && media <= 6.9){
      printf("Aluno em exame.\n");
      scanf("%f", &exame);
      printf("Nota do exame: %.1f\n", exame);
      (media + exame) / 2 >= 5 ? printf("Aluno aprovado.\n") : printf("Aluno reprovado.\n");
      printf("Media final: %.1f\n", ((media + exame)/2));
   }
   else if(media < 5) printf("Aluno reprovado.\n");
   return 0;
}
