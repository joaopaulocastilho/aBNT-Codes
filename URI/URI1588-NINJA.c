#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[25];
	int pts,wins,gols,ind,imp;
	
}time;

int main() {
	int n,T,N,M,i,X,Y;
	time times[2000],time1,time2,maior;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&N,&M);
		for (i=0;i<N;i++){
			times[i].pts = times[i].wins = times[i].gols = times[i].imp = 0;
			times[i].ind = i;
			scanf("%s",&times[i].nome[0]);
		}
		while(M--){
			scanf("%d %s %d %s",&X,&time1.nome[0],&Y,&time2.nome[0]);
			for(i=0;i<N;i++){
				if( !strcmp(time1.nome , times[i].nome) ) time1= times[i];
				if( !strcmp(time2.nome , times[i].nome) ) time2= times[i];
			}
			if (X>Y){
				times[time1.ind].pts += 3;
				times[time1.ind].wins++;
			}
			else if (Y>X){
				times[time2.ind].pts += 3;
				times[time2.ind].wins++;
			}
			else{
				times[time1.ind].pts+= 1;
				times[time2.ind].pts+= 1;
			}
			times[time1.ind].gols+= X;
			times[time2.ind].gols+= Y;
		}
		n=N;
		while(n--){
			maior.pts = maior.gols = maior.ind = maior.wins = -1;
			for(i=0;i<N;i++){
				if (!times[i].imp){
					if (times[i].pts > maior.pts) maior = times[i];
					else if(times[i].pts == maior.pts){
						if(times[i].wins > maior.wins) maior = times[i];
						else if( times[i].wins == maior.wins){
							if(times[i].gols > maior. gols) maior= times[i];
							else if( times[i].gols == maior.gols){
								if(times[i].ind < maior.ind) maior = times[i];
							}
						}
					}
				}	
			}
			printf("%s\n",maior.nome);
			times[maior.ind].imp=1;
		}
	}
	return 0;
}
