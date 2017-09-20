#include <stdio.h>
int main(){
	int i=1,n,maior=-1,I;
	while(i <= 100){
		scanf("%d",&n);
		if (n > maior){
			maior = n;
			I=i;
		}
		i++;
	}
	printf("%d\n",maior);
	printf("%d\n",I);
	return 0;
}
