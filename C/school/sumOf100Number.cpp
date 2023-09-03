#include <stdio.h>
int main(void){
    printf("\n pick a first number:"); int firstNum;
    scanf("%d", &firstNum);
    printf("\n pick a sum of:"); int sumOf;
    scanf("%d", &sumOf);
    int sum = (firstNum + (firstNum + sumOf - 1)) * sumOf / 2 ;
    printf("%d tổng bằng", sum);
}