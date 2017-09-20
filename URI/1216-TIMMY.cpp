#include <stdio.h>
#include <iostream>
#include <string>

#define MAX 1123456

using namespace std;

int main(void){
    double n, a=0, count=0;
    string junk;
    double b;

    while(getline(cin, junk)){
        scanf("%lf\n", &n);
        a += n;
        count++;
    }
    b = a / count;
    printf("%.1lf\n", b);
    return 0;
}
