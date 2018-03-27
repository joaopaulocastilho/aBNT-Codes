#include <stdio.h>
#include <utility>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>

#define MAX 31
#define INF 123456789

using namespace std;

typedef struct{
  int x, y;
}coord_t;

coord_t coord[MAX];

int dist(int i, int j, coord_t coord){
  return abs(i - coord.x) + abs(j - coord.y);
}

int main(void){
  int i, j, k, l, m, n, o, p, t, minSum, mult, first, curSum, mapa[MAX][MAX];
  
  for(k = i = 0; i < 5; i++)
    for(j = 0; j < 5; j++, k++)
      {coord[k].x = i; coord[k].y = j;}
  
  scanf("%d", &t);
  while(t--){
    vector<int> dists;
    minSum = INF;
    memset(mapa, 0, sizeof(mapa));
    scanf("%d", &n);
    for(l = 0; l < n; l++){
      scanf("%d %d %d", &i, &j, &k);
      mapa[i][j] = k;
    } 
    for(i = 0; i < 21; i++)
      for(j = i+1; j < 22; j++)
	for(k = j+1; k < 23; k++)
	  for(l = k+1; l < 24; l++)
	    for(m = l+1; m < 25; m++){
	      for(curSum = o = 0; o < 5; o++){
		for(p = 0; p < 5; p++){
		  if(mapa[o][p] == 0) continue;
		  mult = mapa[o][p];
		  int lmin = min(dist(o, p, coord[i]) * mult, dist(o, p, coord[j]) * mult);
		  lmin = min(lmin, dist(o, p, coord[k]) * mult);
		  lmin = min(lmin, dist(o, p, coord[l]) * mult);
		  lmin = min(lmin, dist(o, p, coord[m]) * mult);
		  curSum += lmin;
		}
	      }
	      //if(curSum) printf("%d\n", curSum);
	      if(curSum < minSum){
		minSum = curSum;
		dists.clear();
		dists.insert(dists.end(), {i, j, k, l, m});
		sort(dists.begin(), dists.end());
	      }
	    }
    for(first = 1, i = 0; i < dists.size(); i++){
      if(first) first = 0;
      else printf(" ");
      printf("%d", dists[i]);
    }
    printf("\n");
  }
}
