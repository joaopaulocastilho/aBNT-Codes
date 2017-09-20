#include <stdio.h>
#include <math.h>

#define MAX 112345

double min(double a, double b, double c){
	if (a < b && a < c) return a;
	if (b < a && b < c) return b;
	return c;
}

int main(void){
	int T = 0;
	double X, Y, Z,A, B, C, croc, misto, trad;;
	while (scanf("%lf %lf %lf", &X, &Y, &Z) != EOF){
		if(X<=0 && Y<=0 && Z<=0) break;
		X*=1000; Y*=1000; Z*=1000;
		A = B = C = croc = misto = trad = 0;
		croc = round(min((X/5),(Y/25),(Z/20)));
		X -= croc*5; Y -= croc*25; Z -= croc*20;
		misto = min(MAX,round(Y/25),round(Z/25));
		Y -= misto*25; Z -= misto*25;
		trad = round(Z/50);
		C = min(round(croc/10), round(misto/10), round(trad/10));
		croc -= C*10; misto -= C*10; trad -= C*10;
		B = min(round(croc/10), round(misto/20), MAX);
		croc -= B*10; misto -= B*20;
		A = round(croc/30);
		printf("Caso #%d: %d Especial, %d Predileta e %d Sortida\n", ++T, (int)A, (int)B, (int)C);
	}
	return 0;
}
