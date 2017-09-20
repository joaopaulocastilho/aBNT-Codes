#include <stdio.h>
int main(){
	int T,PA,PB,anos,flag;
	double GA,GB;
	scanf("%d",&T);
	while (T--){
		anos=flag=0;
		scanf("%d %d %lf %lf",&PA,&PB,&GA,&GB);
//printf("PA/ano=%d\nPB/ano=%d\n",(int)((GA*PA) / 100),(int)((GB*PB) / 100));
		while(PA<=PB){
			PA+= (GA*PA) / 100;
			PB+= (GB*PB) / 100;
			anos++;
			if(anos>100){
				printf("Mais de 1 seculo.\n");
				flag=1;
				break;
			}
		}
		if (!flag) printf("%d anos.\n",anos);
	}

	return 0;
}
