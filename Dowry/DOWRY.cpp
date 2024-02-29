#include <stdio.h>
#include <stdlib.h>
int col, row, dowry;
int **D;//D[row][col]
void input(){
    FILE *f = fopen("DOWRY.INP","r");
    fscanf(f,"%d %d",&row,&col);
    D = (int **)malloc(row*sizeof(int *));
    for(int i = 0; i < row; i++){
        D[i] = (int *)malloc(col*sizeof(int));
    }
    for(int i = 0; i < row;i++)
        for(int j = 0; j < col; j++){
            fscanf(f,"%d",&D[i][j]);
        }
    fclose(f);
}

bool is_feasible(){
    float X = 0.0;
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col; j++){
            X += D[i][j];
        }
    }
    if((X/3) != (int)(X/3)) return 0;
    dowry = X / 3;
    return 1;
}

void output(bool ND, int value, bool yn){// 0N 1D
    FILE *f = fopen("DOWRY.OUT","w");
    char c;
    if(ND) c = 'D'; else c = 'N';
    if(yn){
        fprintf(f,"NO");
    }else{
        fprintf(f,"%c %d \n",c,value);
    }
    fclose(f);
}

int main(){
    input();
    if(!is_feasible()) output(1,1,1);
    int temp_d = 0;
    for(int i = 0; i < row;i++){
        for(int j = 0; j < col; j++){
            temp_d += D[i][j];
        }
        if(temp_d == dowry){
            output(0,1,0);
            break;
        }
        else if(temp_d > dowry){
            output(1,1,1);
        }
    }


}