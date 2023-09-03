#include <stdio.h>
int a,b,tong;

void input(){
    FILE *f = fopen("InOut/TiVaTeo.inp","r");
    fscanf(f,"%d %d",&a,&b);
    fclose(f);
}
void output(int result){
    FILE *f = fopen("InOut/TiVaTeo.out","w");
    fprintf(f,"%d",result);
    fclose(f);
}
void findBoiSo(int j){
    for(int i = j;i>0;i--){
        if(j %i == 0)tong += i;
    }
}

int main(){
    input();
    findBoiSo(a);
    findBoiSo(b);
    output(tong);
    return 0;
}