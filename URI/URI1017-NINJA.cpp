#include<stdio.h>
int main (void) {
	int tmp,kmh;
	double lit;
	scanf("%d %d",&tmp, &kmh);
	lit= kmh*tmp/12.0;
	printf("%.3lf\n" , lit);
	return 0;	}
