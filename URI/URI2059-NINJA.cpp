#include <stdio.h>

int main(void){
    int p, j1, j2, r, a, winner;
    scanf("%d %d %d %d %d", &p, &j1, &j2, &r, &a);
    if(((j1+j2)%2 && !p) || (!((j1 + j2)%2) && p)) winner = 1;
    else winner = 2;
    if(r^a) winner = 1; //(r && !a) || (!r && a)
    else if(r && a) winner = 2;
    printf("Jogador %d ganha!\n", winner);
    return 0;
}
