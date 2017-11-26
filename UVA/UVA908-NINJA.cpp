//Kruskal
#include <stdio.h>
#include <stdlib.h>
#define MAX 1123456

typedef struct edge{
    int u, v, c;
}edge_t;

int n, m, p[MAX], rank[MAX];
edge_t edges[MAX];

int cmp(const void *a, const void *b){
    return ((edge_t *)a)->c - ((edge_t *)b)->c;
}

void Make(int x){p[x] = x; rank[x] = 0;}
int Find(int x){return p[x] == x ? x : p[x] = Find(p[x]);}
void Union(int x, int y){
    int rx = Find(x), ry = Find(y);
    if(rx == ry) return;
    if(rank[ry] < rank[rx]){Union(ry,rx); return;}
    p[rx] = ry;
    if(rank[x] == rank[y]) rank[y]++;
}

int kruskal(){
    int ttl = 0;
    for(int i = 1; i <= n; i++) Make(i);
    for(int i = 1; i <= m; i++)
        if(Find(edges[i].u) != Find(edges[i].v)){
            ttl += edges[i].c;
            Union(edges[i].u, edges[i].v);
        }
    return ttl;
}

int main(void){
    int i, j, k, old, first = 1;

    while( scanf("%d", &n) != EOF){
        for (i = old = 0; i < (n-1); i++){
            scanf("%d %d %d", &u, &v, &c);
            old += c;
        }
        scanf("%d", &k);
        for (i = 1; i <= k; i++)
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].c);
        scanf("%d", &m);
        for(j = 0; j < m; j++, i++)
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].c);
        m += k;
        qsort(edges + 1, n, sizeof(edge_t), &cmp); //COMO n AQUi DeU CeRTO?
        if(first) first = 0; else printf("\n");
        printf("%d\n", old);
        printf("%d\n", kruskal());
    }
    return 0;
}
