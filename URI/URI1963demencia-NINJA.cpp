#include <stdio.h>
int main(void){
	int a1,a2,b1,b2,A,B,resp;
	scanf("%d.%d %d.%d",&a1,&a2,&b1,&b2);
	A = a1*100 + a2; B = b1*100 + b2;
	resp = ((B-A)*10000)/A;
	printf("%d.%02d%%\n",resp/100,resp%100);
	return 0;
}
