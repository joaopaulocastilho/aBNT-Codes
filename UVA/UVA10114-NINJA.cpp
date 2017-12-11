#include <stdio.h>
int main(){
	int f,i,numes,numd,mesid;
	double downp,carvl,divida,porc,meses[110];
	scanf("%d %lf %lf %d",&numes,&downp,&divida,&numd);
	while(numes>0){
		while(numd--){
			scanf("%d %lf",&mesid,&porc);
		for(i=mesid;i<=numes;i++) meses[i]=porc;
		}
//for(i=0;i<numes;i++) printf("%lf\n",meses[i]);
		carvl=downp + divida-(downp + divida) * meses[0];
		i=1;
		downp= divida/numes;
		while(carvl<divida){
			carvl -= meses[i] * carvl;
			divida -= downp;
//printf("%lf %lf %lf\n",carvl,divida,meses[i]);
			i++;
			f=0;
		}
		printf("%d month",i-1);
		if(i-1 == 1) printf("\n");
		else printf("s\n");
		scanf("%d %lf %lf %d",&numes,&downp,&divida,&numd);
	}
	return 0;
}
