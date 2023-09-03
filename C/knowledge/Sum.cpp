#include <stdio.h>

int sum(int a, int b){
    return a+b;
}

int pow(int a, int b){
    int pw;
    pw = a*b;
    return pw;
}

main(){

    int sum1 = sum(1,2);
    int sum2 = sum(3,4);

    int pow1 = pow(2,4);
    
    printf("%d\n", sum1);
    printf("%d", pow1);
    return 0;
}