#include <stdio.h>
int eq;
main(){
    printf("\n nhap chi so EQ");
    scanf("%d", &eq);
    if (eq < 85){
        printf("\n b co EQ thap");
    }
    if ( eq <= 105 && eq >=85){
        printf("\n b co EQ binh thuong");
    }
    if (eq > 105){
        printf("\n b co EQ cao");
    }
return 0;
}    