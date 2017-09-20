#include<stdio.h>
#include<string.h>
int main(){
    char s[500];
    int n,leds=0,i,j;
    scanf("%d",&n);
    while (n--){
        scanf("%s",&s);
        for (i=0;i<=strlen (s);i++){
            switch(s[i]){
                case '0': leds+=6; break;
                case '1': leds+=2; break;
                case '2': leds+=5; break;
                case '3': leds+=5; break;
                case '4': leds+=4; break;
                case '5': leds+=5; break;
                case '6': leds+=6; break;
                case '7': leds+=3; break;
                case '8': leds+=7; break;
                case '9': leds+=6; break;
            }
        }
        printf("%d leds\n",leds);
        leds=0;
    }
    return 0;
}
