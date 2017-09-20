#include<stdio.h>
    int main()  {
    char a[100],b[100],c[100],ave[]="ave",vertebrado[]="vertebrado",carnivoro[]="carnivoro",onivoro[]="onivoro",
    mamifero[]="mamifero",herbivoro[]="herbivoro",invertebrado[]="invertebrado",inseto[]="inseto",hematofago[]="hematofago",
    anelideo[]="anelideo";
    fgets (a,100,stdin);
    fgets (b,100,stdin);
    fgets (c,100,stdin);
    if (a[6]==vertebrado[6] && b[2]==ave[2] && c[4]==carnivoro[4]) {printf("aguia\n");}
    if (a[6]==vertebrado[6] && b[2]==ave[2] && c[4]==onivoro[4]) {printf("pomba\n");}
    if (a[6]==vertebrado[6] && b[2]==mamifero[2] && c[4]==onivoro[4]) {printf("homem\n");}
    if (a[6]==vertebrado[6] && b[2]==mamifero[2] && c[4]==herbivoro[4]) {printf("vaca\n");}
    if (a[6]==invertebrado[6] && b[2]==inseto[2] && c[4]==hematofago[4]) {printf("pulga\n");}
    if (a[6]==invertebrado[6] && b[2]==inseto[2] && c[4]==herbivoro[4]) {printf("lagarta\n");}
    if (a[6]==invertebrado[6] && b[2]==anelideo[2] && c[4]==hematofago[4]) {printf("sanguessuga\n");}
    if (a[6]==invertebrado[6] && b[2]==anelideo[2] && c[4]==onivoro[4]) {printf("minhoca\n");}


    return 0;}
