#include <stdio.h>
int a[1000],max,sl,i;
int main(){
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d",&sl);
    for( i = 0; i < sl; i++){
        printf("\nnhap phan tu so %d: ",i+1);
        scanf("%d",&a[i]);
    }

    for( i = 0; i < sl; i++){
        if(max < a[i]) max = i;
    }
    printf(" so lon nhat la: %d", max);
    return 0;
}