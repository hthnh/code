#include <stdio.h>
int main(){
    printf("nhap so bat dau"); int numStart, sum;
    scanf("%d", &numStart);
    while(numStart % 2 != 0){numStart++;}
    for(int i = numStart; i < 100; i += 2){
        sum += i; printf("%d ", sum);
    }
    
}