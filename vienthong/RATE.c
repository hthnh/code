#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int N, K ,truycap[1000];

void input(){
    FILE *f = fopen("RATE.INP","r");
    fscanf(f,"%d %d",&N,&K);
    for(int i = 0;  i < N; i++){
        fscanf(f,"%d",&truycap[i]);
    }
    
    fclose(f);

}

void output(float result){
    FILE *f = fopen("RATE.OUT","w");
    fprintf(f,"%.6f",result);
    fclose(f);
}
int sum(int a, int b){
    if(a == 1)return truycap[b];
    else return truycap[b] + sum(a-1,b-1);
}
int main(){
    input();
    float max = 0;
    float temp;
    for(int L = K; L < N; L++){
        for(int i = L -1; i <N; i++){
            temp = (float)sum(L,i) / L;
            if(temp > max)max = temp;
        }
    }
    
    output(max);
    return 0;
}