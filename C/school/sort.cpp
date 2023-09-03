#include <stdio.h>
int a[1000],sl,i,j;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


int main(){
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d",&sl);
    for( i = 0; i < sl; i++){
        printf("\nnhap phan tu so %d: ",i+1);
        scanf("%d",&a[i]);
    }

    for (i = (sl-1); i >= 0; i--) {
        for (j = 1; j <= i; j++){
            if (a[j-1] > a[j])
            swap(&a[j-1],&a[j]);
        }
    }
    
    for( i = 0; i < sl; i++){
        printf("%d   ", a[i]);
    }

return 0;

}