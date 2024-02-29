#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int L, R,result = 0;
void input(){
    FILE *f = fopen("DSQUARE.INP","r");
    fscanf(f,"%d %d",&L,&R);
    fclose(f);
}

bool is_square(float a){
    if(a == 1) return 0;
    if((sqrt(a) == (int)sqrt(a)))return 1;
    return 0;
}


void output(int r){
    FILE *f = fopen("DSQUARE.OUT","w");
    fprintf(f,"%d",r);
    fclose(f);
}


int main(){
    int temp;
    input();
    for(int i = L; i < R; i++){
        for(int j = i+1; j <= R; j++){
            temp = i * j;
            for(int x = 2; x < temp; x++)
                if(is_square((float)temp / x)){
                    result++;
                    break;
                    }
        }
    }
    output(result);

}
