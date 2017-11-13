#include <stdio.h>
int main(){
	int H,D,F,dia;
	double alt,U,fadiga;
	scanf("%d %lf %d %d",&H,&U,&D,&F);
	while (H){
		dia=1;
		alt=0;
		fadiga = (F * U) /100;
		while(1){
			alt += U;
			if(alt>H) break;
			U -= fadiga;
			alt-=D;
			if(alt<0) break;
			dia++;
			if (U<0) U=0;
		}
		if(alt > H ) printf("success on day %d\n",dia);
		else printf("failure on day %d\n",dia);
		
		scanf("%d %lf %d %d",&H,&U,&D,&F);
	}
	
	return 0;
}
