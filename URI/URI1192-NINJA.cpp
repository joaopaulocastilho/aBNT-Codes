#include <stdio.h>

int main(void){
	int n, a, b;
	char c;

	scanf("%d", &n);
	while(n--){
		scanf("%d%c%d ", &a, &c, &b);
		if(a == b) printf("%d\n", a*b);
		else if(c >= 'A' && c <= 'Z') printf("%d\n", b-a);
		else printf("%d\n", a+b);
	}

	return 0;
}
