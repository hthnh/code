// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int a = 1, b = 2, c = 3;
    unsigned long long int array[21];
    array[20] = 3265173504;
    array[0] = a;array[1] = b; array[2] = c;
    for(int i = 3; i<20; i++){
        array[i] = array[i-1] * array[i-2] * array[i-3];
    }
    for(int i = 0; i<20; i++){
        printf("%lld ",array[i]);
    }

    return 0;
}