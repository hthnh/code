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
void aa(int start, int end){
    int x = start;
    int temp;
    for(int y = start; y < end; y++){
        temp = di[y];
        for(int i = y; i >= 0; i--){
            if(temp < di[i]){
                temp = di[y];
                break;
            }
            if(temp >= di[i]) point[i] = temp - di[i];
        }
        if(start == end) return;
        aa(start +1,end);
    }
    return;
}


int main(){

    input();
    int start = 0, end = num_of_ship;

    aa(start,end);
    for(int i = 0; i < num_of_ship; i++){
        printf("%d ",point[i]);
    }
}