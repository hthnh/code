#include <stdio.h>
#include <stdlib.h>
int *p,temp,num;
int main(){
    FILE *f = fopen("input.inp","r");
    fscanf(f,"%d",&num);
    p = malloc(num * sizeof(int));
    for(int i = 0; i < num; i++){
        fscanf(f,"%d",&p[i]);
    }
    fclose(f);
    for(int i=0; i<num; i++){
        for(int j=num-1; j>i; j--){
            if(p[j] < p[j-1]){
                temp = p[j];
                p[j] = p[j-1];
                p[j-1] = temp;
            }
        }
    }
    f = fopen("output.out","w");
    for(int i = 0; i < num; i++){
        fprintf(f,"%d ",p[i]);
    }
    fclose(f);

}
