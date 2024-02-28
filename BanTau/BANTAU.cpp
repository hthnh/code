#include <stdio.h>
#include <stdbool.h>
#define max 450
int num_of_er; // energy recharge
int num_of_ship,h = 0;
int di[max],dt[max], point[max],result,pro[2][max];

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

void dupl(){
    for(int i = 0; i < num_of_ship; i++){
        dt[i] = di[i];
    }
}

void sort(int *p, int num){
    int temp;
    for(int i=0; i<num; i++){
        for(int j=num-1; j>i; j--){
            if(p[j] > p[j-1]){
                temp = p[j];
                p[j] = p[j-1];
                p[j-1] = temp;
            }
        }
    }
}


int aa(int sum, int *atk, int *hp, int turn){
    if(!(turn < num_of_ship)){
        turn--;
        if(sum > result) result = sum;
        return sum;
    }
    for(int i = 0; i < num_of_ship; i ++){
        if(atk[i] >= hp[turn]){ 
            sum += atk[i] - hp[turn];
            pro[0][h] = hp[turn];
            pro[1][h] = atk[i];
            h++;
            turn++;
            sum = aa(sum, atk, hp, turn);
        }
        if(atk[i] < hp[turn]){
            h = 0;
            continue;
        }
    }
    return 0;
}


int main(){

    input();
    dupl();
    sort(dt,num_of_ship);

    point[0] = aa(0, dt, di, 0);

    for(int i = 0; i < num_of_ship; i++){
        printf("%d ",dt[i]);
    }
}