#include <stdio.h>
#define max 400
int num_of_er; // energy recharge
int num_of_ship;
int di[max],result[214748364];

void input(){
    FILE *f = fopen("BANTAU.INP","r");
    fscanf(f,"%d",&num_of_ship);
    fscanf(f,"%d",&num_of_er);
    for(int i = 0; i < num_of_ship; i++){
        fscanf(f,"%d",di[i]);
    }
    fclose(f);

}

void output(){
    FILE *f = fopen("BANTAU.OUT","w");
    fclose(f);
}
int a(int power,int b){
    int tong = 0;
    for(int i = 0; i < num_of_ship;i++){
        tong += power - di[i];
    }
    result[b] = tong;
    b = a(di[b],b+1);
    return b;
}
int main(){
    int power = di[0];
    int b =a(di[0],0);
    for(int i = 0; i < b; i++ ){
        printf("%d\n",result[i]);
    }
}