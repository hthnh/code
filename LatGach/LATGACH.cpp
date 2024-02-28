#include <stdio.h>
#include <stdlib.h>
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
};
struct Gach *G;

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
    }
    return so_gach;
}



int main(){
    // for(int i = 0; i < input();i++ ){
    //     printf("%d %d\n%d %d\n%d %d\n%d %d \n\n",G[i].p1.x, G[i].p1.y, G[i].p2.x, G[i].p2.y, G[i].p3.x, G[i].p3.y, G[i].p4.x, G[i].p4.y );
    // }
    for(int i = 0;)

    return 0;
}