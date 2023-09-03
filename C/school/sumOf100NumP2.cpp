#include <stdio.h>

int sumOfFunction(int firstNum,int sumOf){
    int sum = (firstNum + (firstNum + sumOf - 1)) * sumOf / 2 ;
 return sum;
}
int main(void){
    printf("\n pick a first number:"); int firstNum;
    scanf("%d", &firstNum);
    printf("\n pick a sum of:"); int sumOf;
    scanf("%d", &sumOf);
        sumOfFunction(firstNum, sumOf);
    printf("\n %d", sumOfFunction);
}