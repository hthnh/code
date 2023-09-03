#include <stdio.h>

int main(){
    printf("nhap s1, s2"); int s1, s2; scanf("%d%d", &s1, &s2);
    if(s1 <= 0 || s2 <= 0){ printf("nhap sai");
        return 0;
    }
    else{
        int sum = s1 + s2;
        printf("sum = %d, s1 = %d, s2 = %d",sum,s1,s2);
    }
    return 0;
}