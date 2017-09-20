#include <stdio.h>
int main(void){
	int N,resp;
	double C;
	scanf("%d",&N);
	while(N--){
		resp=0;	
		scanf("%lf",&C);
		while(C > 1){
			C/=2;
			resp++;
		}
		printf("%d dias\n",resp);
	}
	
	return 0;
}
