#include <stdio.h>
#include <string.h>

int caso=1;

void rajganha(){ printf("Caso #%d: Raj trapaceou!\n",caso++);}
void sheldonganha(){ printf("Caso #%d: Bazinga!\n",caso++);}
void empate() { printf("Caso #%d: De novo!\n",caso++);	}
	
int main(void){
	int T;
	char sheldon[10],raj[10];
	
	scanf("%d",&T);
	getchar();
	while(T--){
		scanf("%s %s\n",sheldon,raj);
		if( !strcmp(sheldon,raj) ) empate();
		else if( !strcmp(sheldon,"Spock") && (!strcmp(raj,"tesoura") || !strcmp(raj,"pedra") ) ) sheldonganha();
		else if( !strcmp(sheldon,"pedra") && (!strcmp(raj,"tesoura") || !strcmp(raj,"lagarto") ) ) sheldonganha();
		else if( !strcmp(sheldon,"papel") && (!strcmp(raj,"Spock") || !strcmp(raj,"pedra") ) ) sheldonganha();
		else if( !strcmp(sheldon,"tesoura") && (!strcmp(raj,"lagarto") || !strcmp(raj,"papel") ) ) sheldonganha();
		else if( !strcmp(sheldon,"lagarto") && (!strcmp(raj,"Spock") || !strcmp(raj,"papel") ) ) sheldonganha();
		else rajganha();
	}
	return 0;
}
