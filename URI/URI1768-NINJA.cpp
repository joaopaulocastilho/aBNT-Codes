#include <stdio.h>

int main(void){
  int i, n, spaces, stars;

  while(scanf("%d", &n) != EOF){
    for(stars = 1, spaces = n/2; stars <= n; stars += 2, spaces--){
      for(i = 0; i < spaces; i++) printf(" ");
      for(i = 0; i < stars; i++) printf("*");
      printf("\n");
    }
    for(spaces = n/2; spaces; spaces--) printf(" ");
    printf("*\n");
    for(spaces = (n/2)-1; spaces; spaces--) printf(" ");
    printf("***\n\n");
  }

  return 0;
}
