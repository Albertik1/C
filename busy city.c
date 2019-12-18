#include <stdio.h>

#define infinite 1073741823
long int G[300][300]; //adjArray
long int D[300]; //store the shortest distance for start point
long int visited[300]; //record if the vertex visited
long int from[300];
long int cost[300][300];
long int spanning[300][300]; //a MST
int amount_road;
int prims();
void init();


int main(){
    int n, m, A, B, K, i;
    scanf("%d %d", &n, &m);
    init(n);
    for (i=0; i<m; i++){
        scanf("%d %d %d", &A, &B, &K);
        G[A-1][B-1]=G[B-1][A-1]=K;
    }
    printf("%d %d\n", amount_road, prims(n));
    return 0;
}

int prims(int n){
    int u, v, min_distance, no_of_edges, max, i, j;

    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            cost[i][j]=G[i][j];
            spanning[i][j]=0;
        }
    }

    D[0]=0;
    visited[0]=1;
    no_of_edges=n-1;
    amount_road=0;

    for (i=1; i<n; i++){
        D[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }

    while (no_of_edges > 0){
        min_distance=infinite;
        for (i=1; i<n; i++){
            if (visited[i] == 0 && D[i]<min_distance){
                v=i;
                min_distance=D[i];
            }
        }
        u=from[v];
        spanning[u][v]=D[u];
        spanning[v][u]=D[v];
        no_of_edges--;
        visited[v]=1;

        for (i=1; i<n; i++){
            if (visited[i] == 0 && cost[i][v]<D[i]){
                D[i]=cost[i][v];
                from[i]=v;
            }
        }
        max=cost[u][v];
        amount_road++;
    }
    return max;
}

void init(int n){
    int i, j;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            G[i][j]=infinite;
}
