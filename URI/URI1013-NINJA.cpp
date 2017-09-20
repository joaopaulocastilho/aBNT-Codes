#include <stdio.h>
int main(void)	{
	int A,B,C;
	scanf("%d %d %d", &A , &B , &C);
	if (A>B && A>C)
	printf("%d" , A) , printf(" eh o maior\n");
	if (B>A && B>C)
	printf("%d" , B) , printf(" eh o maior\n");
	if (C>A && C>B)
	printf("%d" , C) , printf(" eh o maior\n");return 0;}


