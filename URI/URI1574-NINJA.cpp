#include <stdio.h>

typedef struct{
	char dir[20];
	int val;
}comando;

int main(){
	int t,n,i,robo,pos;
	comando comandos[200];
	scanf("%d",&t);
	while (t--){
		robo = 0;
		scanf("%d",&n);
		getchar();
		for (i=1;i<=n;i++){
			fgets( comandos[i].dir,20,stdin);
			switch (comandos[i].dir[0]){
				case 'L': comandos[i].val = -1; break;
				case 'R': comandos[i].val = 1;	break;
				case 'S':
					if(comandos[i].dir[9] != '\n'  ){
						pos= (comandos[i].dir[9] - 48) + ( (comandos[i].dir[8] - 48) * 10 );
					}
					else pos= (comandos[i].dir[8] - 48);
					comandos[i].val = comandos[pos].val;
			}
			robo+= comandos[i].val;
		}
		printf("%d\n",robo);
	}
	
	return 0;
}
