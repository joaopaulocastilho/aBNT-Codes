#include <stdio.h>

int formatriangulo(int a,int b,int c){
	if(a+b> c && a+c>b && b+c>a) return 1;
	return 0;
}


int main(void){
	int A,B,C,D;
	scanf("%d %d %d %d",&A,&B,&C,&D);
	if ( formatriangulo(A,B,C) || formatriangulo(D,B,C) || formatriangulo(A,D,C) || formatriangulo(A,B,D) ) printf("S\n");
	else printf("N\n");

	return 0;
}
