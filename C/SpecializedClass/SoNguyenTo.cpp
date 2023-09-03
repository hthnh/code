#include <stdio.h>
int a, SoNguyenTo;
int main(void){
    printf("nhap so nguyen to");
    scanf("%d", &SoNguyenTo);
    for(int i = 2; i <= SoNguyenTo; i++) 
        if(SoNguyenTo % i ==0) 
            a++;
        if(a < 2) printf("\nday la so nguyen to");
            else printf("\nday khong phai la so nguyen to");

}