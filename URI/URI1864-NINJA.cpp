#include <stdio.h>
int main(void){
	int N;
	char str[] = "LIFE IS NOT A PROBLEM TO BE SOLVED";
	scanf("%d",&N);
	str[N] = '\0';
	puts(str);
	return 0;
}
