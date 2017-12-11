#include <stdio.h>

#define MAX 112345678

int p[MAX], rank[MAX];

void Make(int x){p[x] = x; rank[x] = 0;}
int Find(int x){return p[x] == x ? x : p[x] = Find(p[x]);}
void Union(int x, int y){
    int rx = Find(x), ry = Find(y);
    if(rx == ry) return;
    if(rank[ry] < rank[rx]){Union(ry, rx); return;}
    p[rx] = ry;
    if(rank[x] == rank[y]) rank[y]++;
}

int main (void){
    int t, n, u, v, succ, fail, first = 1;
    char c, line[100];
    scanf("%d", &t);
    while(t--){
        succ = fail = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) Make(i);
        while(getchar() != '\n');
        while( fgets(line, 100, stdin) && sscanf(line, " %c %d %d", &c, &u, &v) == 3){
            if(c == 'c') Union(u, v);
            else if(Find(u) == Find(v)) succ++;
            else fail++;
        }
        if(first) first = 0; else printf("\n");
        printf("%d,%d\n", succ, fail);
    }
    return 0;
}
