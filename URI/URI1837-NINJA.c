#include <stdio.h>
#include <stdlib.h>
int main() {
	int a,b,q,r;
	scanf("%d %d",&a,&b);
		for (q=-1000; ;q++)
			for(r=-1000;r<abs(b);r++) if (a == b * q + r && r>=0){
										printf("%d %d\n",q,r);
										return 0;
									}
									
}
