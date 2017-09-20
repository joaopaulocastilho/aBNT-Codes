#include <stdio.h>

int main(void){
	int hora,min,hora8,hora4,hora2,hora1,min32,min16,min8,min4,min2,min1;
	while(scanf("%d:%d",&hora,&min) != EOF){
		hora8 = hora/8;	hora-= hora8 * 8;
		hora4 = hora/4; hora -= hora4 * 4;
		hora2 = hora/2; hora -= hora2 * 2;
		hora1 = hora;
		min32 = min/32; min -= min32 * 32;
		min16 = min/16; min -= min16 * 16;
		min8 = min/8; min -= min8 * 8;
		min4 = min/4; min -= min4 * 4;
		min2 = min/2; min -= min2 * 2;
		min1 = min;
		
		printf(" ____________________________________________\n");
		printf("|                                            |\n");
		printf("|    ____________________________________    |_\n");
		printf("|   |                                    |   |_)\n");
		printf("|   |   8         4         2         1  |   |\n");
		printf("|   |                                    |   |\n");
		printf("|   |   %c         %c         %c         %c  |   |\n",hora8 ? 'o' : ' ',hora4 ? 'o' : ' ',hora2 ? 'o' : ' ',hora1 ? 'o' : ' ');
		printf("|   |                                    |   |\n");
		printf("|   |                                    |   |\n");
		printf("|   |   %c     %c     %c     %c     %c     %c  |   |\n",min32 ? 'o' : ' ',min16 ? 'o' : ' ',min8 ? 'o' : ' ',
		min4 ? 'o' : ' ',min2 ? 'o' : ' ',min1 ? 'o' : ' ');
		printf("|   |                                    |   |\n");
		printf("|   |   32    16    8     4     2     1  |   |_\n");
		printf("|   |____________________________________|   |_)\n");
		printf("|                                            |\n");
		printf("|____________________________________________|\n");
		printf("\n");
	}


	return 0;
}
