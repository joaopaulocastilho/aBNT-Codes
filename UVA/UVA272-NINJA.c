#include <stdio.h>

#define MAX 1123456
int main (){
	char txt[MAX],c;
	int i=0,f=0;
	for(i=0;	scanf("%c",&c)!=EOF	;i++){
		if(c=='"' && f==0){
			f=1;
			txt[i]='`'; txt[i+1]='`';
			i++;
		}else if(c=='"' && f==1){
			f=0;
			txt[i]='\'' ;txt[i+1]='\'';
			i++;
		}else txt[i]=c;
	} 
	printf("%s",txt);	
	return 0;
}
