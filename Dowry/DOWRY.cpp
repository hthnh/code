#include <stdio.h>
#include <stdlib.h>
int col;//j
int row;//i
int dowry;
int **D;//D[row][col] D[i][j];
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
// 0N 1D || value || 0YES 1NO
void output(bool ND, int value, bool yn){
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

int sum_horizontal(int i, int temp_d){
    for(int j = 0; j < col; j++){
        temp_d += D[i][j];
    }
    return temp_d;
}

int sum_vertical(int j, int temp_d){
    for(int i = 0; i < row; i++){
        temp_d += D[i][j];
    }
    return temp_d;
}

bool check_divide_horizontal(int i_s ,int i_e){
    int temp_d = 0;
    for(int i = i_s; i < i_e; i++){
       temp_d = sum_horizontal(i, temp_d);
        if(temp_d == dowry){
            return 1;
        } else if(temp_d > dowry) return 0;
    }
}

int divide_horizontal(int i_s ,int i_e){
    int temp_d = 0;
    for(int i = i_s; i < i_e; i++){
       temp_d = sum_horizontal(i, temp_d);
        if(temp_d == dowry){

        }
    }
}

bool check_divide_vertical(int j_s,int j_e){
    int temp_d = 0;
    for(int j = j_s; j < j_e; j++){
       temp_d = sum_vertical(j, temp_d);
        if(temp_d == dowry){
            return 1;
        } else if(temp_d > dowry) return 0;
    }
}

void first_divide(){
    int i_s = 0;
    int j_s = 0;
    if(!check_divide_horizontal(i_s,row)){
        if(!check_divide_vertical(j_s,col)){
            return output(1,1,1);
        }
    }
    
}

int main(){
    input();
    if(!is_feasible()) output(1,1,1);

    first_divide();
    



}