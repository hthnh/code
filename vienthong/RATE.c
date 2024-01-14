#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int N, K ,truycap[1000];

void input(){
    FILE *f = fopen("RATE.INP","r");
    fscanf(f,"%d %d",&N,&K);
    char temp,temp1[2];
    int i = -1;
    while ((temp = fgetc(f))!= EOF){
        if(temp != 32){
            temp1[0] = temp;
            truycap[i] = atoi(temp1);
            i++;
        }
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
