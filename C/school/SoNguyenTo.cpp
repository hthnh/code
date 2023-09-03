#include <stdio.h>


int check= 0,a[10000],i,sl,b;

void kiemtrasonguyento(int SoNguyenTo){
    b = 0;
    for(int i = 2; i <= SoNguyenTo; i++) 
        if(SoNguyenTo % i ==0) 
            b++;
        if(b == 1) check++;
}


int main(){
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d",&sl);
    for( i = 0; i < sl; i++){
        printf("\nnhap phan tu so %d: ",i+1);
        scanf("%d",&a[i]);
    }

    for( i = 0; i < sl; i++){
        kiemtrasonguyento(a[i]);
    }

    printf("co %d so nguyen to trong mang", check);
    return 0;


}