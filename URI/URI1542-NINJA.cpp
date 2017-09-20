#include <stdio.h>
int main(){
	double q,d,p;
	int resp;
	scanf("%lf",&q);
	while (q){
		scanf("%lf %lf",&d,&p);
		resp = (((q*d)/(p-q)) * p);
		printf("%d ",resp);
		if (resp == 1 ) printf("pagina\n");
		else printf("paginas\n");
		scanf("%lf",&q);
	}
	
	return 0;
}
