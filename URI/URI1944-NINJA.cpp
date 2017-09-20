#include <stdio.h>
#include <string.h>

int inversas(char a[],char b[]){
	int i,j;
//printf("Comparando %s com %s\n",a,b);
	for(i=0,j=3; i<=3 && j>=0;i++,j--){
		if(a[i] != b[j]) return 0;
	}
	return 1;
}

int main(void){
	int i,j,k,N,resp = 0;
	char letras[10],c,painel[200][10];
	strcpy(painel[0],"FACE");
	scanf("%d",&N);
	for(j=1,k=0;k<N;k++){
		for(i=0;i<4;){
			scanf("%c",&c);
			if(c >= 'A' && c <= 'Z') letras[i++] = c;
		}
		letras[4] = '\0';
//puts(letras);
		if(inversas(painel[j-1],letras)){
			resp++;
			if(j>1) j--;
		}
		else strcpy(painel[j++],letras);
	}
	printf("%d\n",resp);
	return 0;
}
