#include <stdio.h>
#include <stdbool.h>
#define max 450
int num_of_er; // energy recharge
int num_of_ship;
int di[max],dt[max], point[max];

void input(){
    FILE *f = fopen("BANTAU.INP","r");
    fscanf(f,"%d",&num_of_ship);
    fscanf(f,"%d",&num_of_er);
    for(int i = 0; i < num_of_ship; i++){
        fscanf(f,"%d",&di[i]);
    }
    fclose(f);
}

void output(){
    FILE *f = fopen("BANTAU.OUT","w");
    fclose(f);
}



int main(){

    input();
    int x = 0;
    int temp;
    for(int y = 0; y < num_of_ship; y++){
        temp = di[y];
        for(int i = y; i >= 0; i--){
            if(temp < di[i]){
                temp = di[y];
                break;
            }
            if(temp >= di[i]) point[i] = temp - di[i];
        }
    }
    for(int i = 0; i < num_of_ship; i++){
        printf("%d ",point[i]);
    }
}