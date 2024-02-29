#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int **result;
struct coordinates{
    int x;
    int y;
}; typedef struct coordinates local;
struct Gach{
    local p1;
    local p2;
    local p3;
    local p4;
    int acreage;
    int id_link;
};
struct Gach *G;
int current_link = 1;

int input(){
    int so_gach;
    FILE *f = fopen("LATGACH.INP","r");
    fscanf(f,"%d",&so_gach);
    G = (struct Gach *)malloc(so_gach*sizeof(struct Gach));
    int X,Y,D,C;
    for(int i = 0; i < so_gach; i++){
        fscanf(f,"%d %d %d %d",&X,&Y,&D,&C);
        G[i].p1.x = X;
        G[i].p1.y = Y;

        G[i].p2.x = X;
        G[i].p2.y = Y+C;
        
        G[i].p3.x = X+D;
        G[i].p3.y = Y;

        G[i].p4.x = X+D;
        G[i].p4.y = Y+C;
        G[i].acreage = C*D;
        G[i].id_link = 0;
    }
    return so_gach;
}
void output(int r){
    FILE *f = fopen("LATGACH.OUT","w");
    fprintf(f,"%d",r);
    fclose;
}
//equa 0y 1x
bool check_equa(local a1, local a2, local b1, local b2, bool yn){
    if(yn){
        if(a1.x == b1.x)
            if(a2.x == b2.x)
                return 1;

    }else{
        if(a1.y == b1.y)
            if(a2.y == b2.y)
                return 1;
    }
    return 0;
}
//equa 0y 1x
bool check_in(local a1, local a2, local b1, local b2, bool yn){
    if(yn){
        if(b1.y <= a1.y)
            if(b1.y >= a2.y)
                return 1;
        if(b2.y >= a2.y)
            if(b2.y <= a1.y)
                return 1;
    }
    if(!yn){
        if(b1.x >= a1.x)
            if(b1.x <= a2.x)
                return 1;
        if(b2.x <= a2.x)
            if(b2.x >= a1.x)
                return 1;
    }
return 0;
}



int main(){
    int num = input();
    
    for(int i = 0; i < num; i++ ){
        if(G[i].id_link == 0){
            G[i].id_link = current_link;
            current_link++;
        }     
        for(int j = 0; j < num; j++){
            if(i == j) continue;
            if(check_equa(G[i].p1,G[i].p3,G[j].p2,G[j].p4,0))
                if(check_in(G[i].p1,G[i].p3,G[j].p2,G[j].p4,0))
                    G[j].id_link = G[i].id_link;
            if(check_equa(G[i].p1,G[i].p2,G[j].p3,G[j].p4,1))
                if(check_in(G[i].p1,G[i].p2,G[j].p3,G[j].p4,1))
                    G[j].id_link = G[i].id_link;
            if(check_equa(G[i].p4,G[i].p3,G[j].p2,G[j].p1,1))
                if(check_in(G[i].p4,G[i].p3,G[j].p2,G[j].p1,1))
                    G[j].id_link = G[i].id_link;
            if(check_equa(G[i].p2,G[i].p4,G[j].p1,G[j].p3,0))
                if(check_in(G[i].p2,G[i].p4,G[j].p1,G[j].p3,0))
                    G[j].id_link = G[i].id_link;
        }
    }

    for(int i = 0; i < num;i++ ){
        printf("%d %d\n%d %d\n%d %d\n%d %d\n%d   %d\n\n",G[i].p1.x, G[i].p1.y, G[i].p2.x, G[i].p2.y, G[i].p3.x, G[i].p3.y, G[i].p4.x, G[i].p4.y,G[i].acreage,G[i].id_link );
    }
    result = (int **)calloc(2,sizeof(int*));
    result[0] = (int *)calloc(num,sizeof(int));
    result[1] = (int *)calloc(num,sizeof(int));
    for(int i = 0; i < num; i++){
        result[0][G[i].id_link] += G[i].acreage;
        result[1][G[i].id_link] += 1;
    }
    int max =0;
    for(int i = 0; i < num; i++){
        if(result[1][i] > 1)
        if(max < result[0][i]) max = result[0][i];
    }
    output(max);
    return 0;
}