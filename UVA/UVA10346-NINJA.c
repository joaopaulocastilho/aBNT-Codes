#include<stdio.h>
	int main(){
		int cigarros, need,resp=0,bit;
		
		while (scanf("%d %d",&cigarros,&need)!= EOF){
			resp=cigarros;
			if (need>1){
				while (cigarros>= need){
					bit=(cigarros%need);
					cigarros/=need;
					resp+=cigarros;
					cigarros+=bit;
				}
			}	
			printf("%d\n",resp); 
		}
	return 0;
}
