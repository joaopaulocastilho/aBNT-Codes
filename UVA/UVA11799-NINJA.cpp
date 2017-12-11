#include <stdio.h>
int main(){
	int T,maior,n,N,cse=1;
	scanf("%d",&T);
	while (T--){
		maior=-1;
		scanf("%d",&N);
		for(int i=0;i< N;i++){
			scanf("%d",&n);
			if (n>maior) maior=n;
		}
		printf("Case %d: %d\n",cse++,maior);
	}
	return 0;
}
