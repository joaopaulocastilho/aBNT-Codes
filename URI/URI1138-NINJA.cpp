#include <stdio.h>
#include <string.h>
int main() {
	int A,B,dig[10];
	while(scanf("%d %d",&A,&B),B){
		memset(dig,0,sizeof(dig) );
		for(int i=A; i<=B ; i++){
			int j=i;
			if(j%1000 == 0 && j+1000<=B){
				for(int k =0; k<10;k++) dig[k] += 300;
					j/=1000;
					while(j){
						dig[j%10]+=1000;
						j/=10;
					}
					i+=999;
			}
			else if(j%100 == 0 && j+100<=B){
				for(int k=0;k<10;k++) dig[k] += 20;
				j/=100;
				while(j){
					dig[j%10]+=100;
					j/=10;
				}
				i+=99;
			}
			else if (j % 10 == 0 && j+10 <=B){
				for(int k=0;k<10;k++) dig[k]++;
				j/=10;
				while(j){
					dig[j%10] += 10;
					j/=10;
				}
				i+=9;
			}
			else{
				while(j){
					dig[j%10] ++;
					j /=10;
				}
			}
		}	
		for(int i=0;i<9;i++) printf("%d ",dig[i]);
		printf("%d\n",dig[9]);
	}
	
	return 0;
}
