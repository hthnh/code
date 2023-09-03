#include<stdio.h>
int trcgiam;//số tiền trước BL
float saugiam;//số tiền sau BL
main(){
    printf("\n nhap so tien truoc khi giam");
    scanf("%d",&trcgiam);
    if (trcgiam > 0){
        saugiam = trcgiam * 0.5;
        printf("\n sau BL gia tri mon hang la%f",saugiam);
    }
    else printf("\n so tien khong co that");
    return 0;
}