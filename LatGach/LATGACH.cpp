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
        
        G[i].p4.x = X+D;
        G[i].p4.y = Y;

        G[i].p3.x = X+D;
        G[i].p3.y = Y+C;
        G[i].acreage = C*D;
        G[i].id_link = 0;
    }
    return so_gach;
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
            if((G[i].p1.x == G[j].p3.x || G[i].p1.x == G[j].p4.x) && (G[i].p1.y <= G[j].p3.y || G[i].p2.y >= G[j].p3.y)) G[j].id_link = G[i].id_link;

            if((G[i].p2.x == G[j].p3.x || G[i].p2.x == G[j].p4.x) && (G[i].p1.y <= G[j].p4.y || G[i].p2.y >= G[j].p4.y)) G[j].id_link = G[i].id_link;


            if((G[i].p1.x == G[j].p3.x || G[i].p1.x == G[j].p2.x) && (G[i].p1.x <= G[j].p2.x || G[i].p4.x >= G[j].p2.x)) G[j].id_link = G[i].id_link;

            if((G[i].p4.x == G[j].p3.x || G[i].p4.x == G[j].p2.x) && (G[i].p1.x <= G[j].p3.x || G[i].p4.x >= G[j].p3.x)) G[j].id_link = G[i].id_link;


            if((G[i].p2.x == G[j].p1.x || G[i].p2.x == G[j].p4.x) && (G[i].p1.x <= G[j].p2.x || G[i].p4.x >= G[j].p2.x)) G[j].id_link = G[i].id_link;

            if((G[i].p3.x == G[j].p1.x || G[i].p3.x == G[j].p4.x) && (G[i].p1.x <= G[j].p3.x || G[i].p4.x >= G[j].p3.x)) G[j].id_link = G[i].id_link;


            if((G[i].p3.x == G[j].p2.x || G[i].p4.x == G[j].p2.x) && (G[i].p3.y >= G[j].p2.y || G[i].p4.y <= G[j].p2.y)) G[j].id_link = G[i].id_link;

            if((G[i].p3.x == G[j].p1.x || G[i].p4.x == G[j].p1.x) && (G[i].p3.y >= G[j].p1.y || G[i].p4.y <= G[j].p1.y)) G[j].id_link = G[i].id_link;

        }
    }

    for(int i = 0; i < num;i++ ){
        printf("%d %d\n%d %d\n%d %d\n%d %d\n%d   %d\n\n",G[i].p1.x, G[i].p1.y, G[i].p2.x, G[i].p2.y, G[i].p3.x, G[i].p3.y, G[i].p4.x, G[i].p4.y,G[i].acreage,G[i].id_link );
    }
    return 0;
}