#include <cstdio>

int main(void){
    int tc;
    char junk[112345];
    while(scanf("%d", &tc) != EOF){
      printf("%d", tc);
      while(tc--){
	getchar();
	fgets(junk, 112345, stdin);
	printf("I am Toorg!\n");
      }
    }
    return 0;
}
