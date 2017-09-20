#include <stdio.h>
int main(void){
	int A,B,C;
	scanf("%d %d %d",&A,&B,&C);
	if(	(B<A && (C>=B || A-B > B-C )) || (B==A && C>B) || (B>A && C>B && C-B >= B-A)) printf(":)\n");
	else printf(":(\n");

	return 0;
}
