#include <stdio.h>
int x[200], y[200];
int num_of_point;
int SS = 0;



void input(){
    FILE *f = fopen("InOut/Straight.inp","r");
    fscanf(f,"%d",&num_of_point);
    for (int i = 0; i < num_of_point; i++){
        fscanf(f,"%d %d",&x[i],&y[i]);
    }
    fclose(f);
}

int checkSS(int x, int y, int x1, int y1,int x2, int y2, int x3, int y3){
    if(x == x1) 
        if(x2 == x3)
            return 0;
    if(y == y1)
        if(y2 == y3)
            return 0;
    if(x - x1 == x2 - x3)
        if(y - y1 == y2 - y3)
            return 0;
    return 1;
}

void progress(){
    for(int i = 0;i<num_of_point;){
        i++;
        for(int j = i; j<num_of_point;){
            j++;
            for(int k = j; k < num_of_point;){
                k++;
                for(int m = k; m < num_of_point;){
                    m++;
                    if(checkSS(x[m],y[m],x[k],y[k],x[j],y[j], x[i], y[i])) SS+=1;
                }
            }
        }
    }

}


void output(int result){
    FILE *f = fopen("InOut/Straight.out","w");
    fprintf(f,"%d",result);
    fclose(f);
}

int main(){
    input();
    progress();
    output(SS);

    
    return 0;
}