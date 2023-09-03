#include <stdio.h>
int a[1000],max,sl,i,b,sum;
int main(){
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d",&sl);
    for( i = 0; i < sl; i++){
        printf("\nnhap phan tu so %d: ",i+1);
        scanf("%d",&a[i]);
    }

    for( i = 0; i < sl; i++){
        if( i % 2 == 0)
            if(a[i] %2 != 0){ 
                sum += a[i];
                b++;
            }
    }
    sum /= b;

    printf("trung binh cong la: %d", sum);

return 0;
}


