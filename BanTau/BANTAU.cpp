#include <stdio.h>
#include <stdbool.h>
#define max 450
int num_of_er; // energy recharge
int num_of_ship,dem = 0;
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
    fprintf(f, "%d", dem);
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


int process(int a, int gt, int val, int k)
{
    int tam, tam1 = k;
    for (int i = 0; i < num_of_ship; i++)
    {
        if (dt[i] != val) tam1 = k + 1;
        if (dt[i] == val && i > 0) tam1 = k;
        if (dt[i] < di[a] || a >= num_of_ship) break;
        if (tam1 > num_of_er) continue;
        if (dt[i] >= di[a])
        {
            tam = gt + dt[i] - di[a];
            if (a == num_of_ship-1)
            {
                if (k == 0) dem = tam;
                if (k != 0 && tam < dem) dem = tam; 
            }
            process(a+1, tam, dt[i], tam1);
        }
    }
}



int main(){

    input();
    dupl();
    sort(dt,num_of_ship);

    for (int i = 0; i < num_of_ship; i++)
    {
        if (dt[i] < di[0]) break;
        if (dt[i] >= di[0])
        {
            int tam;
            tam = dt[i] - di[0];
            process(1, tam, dt[i], 0);
        }
    }
    output();

}