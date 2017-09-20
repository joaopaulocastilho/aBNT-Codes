#include <stdio.h>
int main(void){
	int C,N;
	scanf("%d",&C);
	while(C--){
		scanf("%d",&N);
		printf("%d\n", !(N%2) ? 0 : 1);
	}
	return 0;
}
