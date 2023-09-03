#include <stdio.h>
int a[1000],sl,i;
int main(){
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d",&sl);
    for( i = 0; i < sl; i++){
        printf("\nnhap phan tu so %d: ",i+1);
        scanf("%d",&a[i]);
    }

    for( i = 0; i < sl; i++){
        if(a[i] < 0) a[i] = 0;
    }

    for( i = 0; i < sl; i++){
        printf("%d   ", a[i]);
    }
    
    return 0;
}