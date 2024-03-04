#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MaxN 10000
#define INF LLONG_MAX

typedef long long ll;

int n; // so thanh pho
int m; // so duong
int s = 1; // bat dau
int result[3][MaxN]; //0V 1U 2R
int step = 1;
bool mark[MaxN];
ll dist[MaxN];
int adj[MaxN][MaxN];

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
                    result[0][step] = v;
                    result[1][step] = u;
                    result[2][step] = dist[v];
                    step++;
                }
            }
        }
    }
}

void input(){
    FILE *f = fopen("UPGRADE.INP","r");
    fscanf(f,"%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        fscanf(f,"%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }
    fclose(f);
}

void output(){
    FILE *f = fopen("UPGRADE.OUT","w");
    
    
    fclose(f);
}

int main() {
    input();
    Dijkstra(s);
    output();
    return 0;
}

