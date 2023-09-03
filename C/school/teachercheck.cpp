#include <stdio.h>
int main(void){
    printf("\nnhap so can tinh va so luong so can tinh"); int a, b; // a la so can tinh, b la so luong so can tinh
    scanf("%d%d", a, b);
    for(int i = 0; i <= b; i++){
        int tong = a + i;
    }
    printf("voi so can tinh la %d ta co tong la%d",a,tong);
}