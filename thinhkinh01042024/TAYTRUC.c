#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int so_chua,*vi_tri_chua,S = 0;
float input(){
    FILE *f = fopen("TAYTRUC.INP","r");
    int so_ho_lo,sum = 0;
    fscanf(f,"%d %d",&so_chua,&so_ho_lo);
    vi_tri_chua = (int *)calloc(so_chua,sizeof(int));
    for(int i = 0; i < so_chua; i++) fscanf(f,"%d",vi_tri_chua+i);
    fclose(f);
    for(int i = 0; i < so_chua; i++) sum+=*(vi_tri_chua+i);
    return sum/so_chua;
}
bool bo_qua_chua(int i, int so_ho_lo){
    int sum = 0, sum1 = 0;
    for(int j = i;j < so_ho_lo+i;j++) sum+=*(vi_tri_chua+j);
    for(int j = i+so_ho_lo;j < so_ho_lo*2+i;j++) sum1+=*(vi_tri_chua+j);
    if(sum1 > sum ) return true;
    else return false;

}
void output(){
    FILE *f = fopen("TAYTRUC.OUT","w");
    fprintf(f,"%d",S);
    fclose(f);
}
int main(){
    int so_ho_lo_dang_co = 0,avg;
    bool co_the_lay;
    avg = (int)input();
    for(int i = 0; i < so_chua-1;i++){
        if(*(vi_tri_chua+i) < *(vi_tri_chua+i+1)){
            if(so_ho_lo_dang_co > 0){
                if(bo_qua_chua(i, so_ho_lo_dang_co)){
                    i+=so_ho_lo_dang_co-1;
                    so_ho_lo_dang_co = 0;
                    continue;
                }
                so_ho_lo_dang_co--;
                co_the_lay = false;
                continue;
            }
            
        }
        else if(so_ho_lo_dang_co == 0 || co_the_lay == true){
            so_ho_lo_dang_co+=1;
            S+=*(vi_tri_chua+i);
            co_the_lay = true;
            continue;
        }
    }

    output();
    free(vi_tri_chua);
    return 0;
}