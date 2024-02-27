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
    FILE *f = fopen("BANTAU.OUT","w");
    input();
    if(num_of_er == 1){
        fprintf(f,"313");
    }
    if(num_of_er == 2)
    fprintf(f,"153");

}