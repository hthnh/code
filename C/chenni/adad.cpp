#include <stdio.h>
#include <cstdlib>
int *ptr;


main(){
    while(1){
        ptr = (int*) malloc(100 * sizeof(int));
    }
    return 0;
}