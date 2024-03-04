#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MaxN 1000
#define INF 1000001

typedef long long ll;

int n; // so thanh pho
int m; // so duong
int s = 1; // bat dau
bool mark[MaxN];
ll dist[MaxN];
int adj[MaxN][MaxN];
int u[MaxN], v[MaxN], w[MaxN],u_t[MaxN],v_t[MaxN],w_t[MaxN];

void Dijkstra(int s) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        mark[i] = false;
    }
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        int u = -1;
        for (int j = 1; j <= n; j++) {
            if (!mark[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        if (dist[u] == INF) {
            break;
        }
        mark[u] = true;
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != 0) {
                ll w = adj[u][v];
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}

void input(){
    FILE *f = fopen("UPGRADE.INP","r");
    fscanf(f,"%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        fscanf(f,"%d %d %d", &u[i], &v[i], &w[i]);
    }
    fclose(f);
}


// void input(){
//     scanf("%d %d", &n, &m);
//     for (int i = 0; i < m; i++) {
//         scanf("%d %d %d", &u[i], &v[i], &w[i]);
//     }
// }

void dupl(int f){
    for(int i = 0; i < m; i++ ){
        if( i == f) continue;
        u_t[i] = u[i];
        v_t[i] = v[i];
        w_t[i] = w[i];
    }
    for(int i = 0; i < m; i++){
        if( u_t[i] == 0 ) continue;
        adj[u_t[i]][v_t[i]] = w[i];
        adj[v_t[i]][u_t[i]] = w[i];
    }
}



void output(int r){
    FILE *f = fopen("UPGRADE.OUT","w");    
    fprintf(f,"%d",r);
    fclose(f);
}

// void output(int r){
//     printf("%d",r);
// }

void reset(){
    memset(adj, 0,MaxN*MaxN*sizeof (int));
    memset(u_t, 0, MaxN*sizeof(u_t[0]));
    memset(v_t, 0, MaxN*sizeof(v_t[0]));
    memset(w_t, 0, MaxN*sizeof(w_t[0]));
    memset(dist, 0, MaxN*sizeof(w_t[0]));
}

int main() {
    int temp1 = 0;
    input();
    dupl(-1);
    Dijkstra(s);
    int temp = dist[n];
    reset();
    for(int i = 0; i < m; i++){
        dupl(i);
        Dijkstra(s);
        if( dist[n] != temp) temp1++; 
        reset();
    }
    output(temp1);
    return 0;
}