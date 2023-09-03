#include <stdio.h>


int find_sum(int a, int b)
{ 
//user function
   int sum = a + b;
    return sum;
}

int main(void){ // don't need return
    int sum = find_sum(200000000,250000000);// call function and add a =1 b =3
    printf("%d", sum);
}

