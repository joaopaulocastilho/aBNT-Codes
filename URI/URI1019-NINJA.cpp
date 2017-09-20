#include<stdio.h>
	int main(void) {
		
	int N,h,m,s;
	scanf("%d", &N);
	h=N/60;
	m=(N-h*60)/60;
	s=(N-h*60)-(m*60)/60;
	printf("%d:%d:%d", h , m ,s);
	return 0;
	
	}
