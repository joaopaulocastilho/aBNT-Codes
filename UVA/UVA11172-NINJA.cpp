#include <stdio.h>
int main(){
	long long int A,B;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%llu %llu",&A,&B);
		printf("%c\n",A > B ? '>' : A < B ? '<' : '=');
	}

	return 0;
}
