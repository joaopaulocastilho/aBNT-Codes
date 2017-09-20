#include <stdio.h>
int main(void){
	int N;
	scanf("%d",&N);
	printf("Top ");
	if(N == 1) printf("1\n");
	else if(N <= 3)printf("3\n");
	else if(N <= 5)printf("5\n");
	else if(N <= 10)printf("10\n");
	else if(N <= 25)printf("25\n");
	else if(N <= 50)printf("50\n");
	else if(N <= 100)printf("100\n");
	return 0;
}
