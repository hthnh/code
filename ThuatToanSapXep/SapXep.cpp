#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define max 100000
int a[max],result[max];
int input(){
    FILE *f = fopen("SAPXEP.INP","r");
    int num;
    fscanf(f,"%d",&num);
    for(int i = 0; i < num; i++){
        fscanf(f,"%d",&a[i]);
    }
    return num;
    fclose(f);
}

int move(int start, int end, bool ES){//0 cuoi 1 move ve da`u
    int temp;
    end--;
    if(ES){
        temp = a[start];
        for(int i = start; i > end; i-- ){
            a[i] = a[i-1];
        }
        a[end] = temp;
    }else{
        temp = a[start];
        for(int i = start; i < end; i++ ){
            a[i] = a[i+1];
        }
        a[end] = temp;
    }
    return abs(end - start);
}
void output(int N){
    FILE *f = fopen("SAPXEP.OUT","w");
    for(int i = 0; i < N; i++){
        // fprintf(f,"%d\n",a[i]);
        fprintf(f,"%d\n",result[i+1]);
    }
}

int main(){
    int N = input();
    int x = 1;
    int y = N;
    int b = 1;
    while( b <= N){
        for(int i = 0; i < N; i++){
            if(a[i] == x && b % 2 != 0 ){
                result[b] = move(i,x,1);x++;
                break;
            }
            if(a[i] == y && b % 2 == 0 ){
                result[b] = move(i, y, 0);y--;
                break;
            }
        }
        b++;
    }
    output(N);
}