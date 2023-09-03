#include <stdio.h>
int a2,b2,numCheck2;

void Fibonacci(int a, int b, int numCheck){
int a1 = a,b1 = b, n=0,temp = 0;
while(b <= numCheck){
    temp = a;
    a += b;
    b = temp;
    n++;
}
//b la so fibonacci tai n
if(b==numCheck) printf("\n%d va %d tai %d", a1, b1,n);
}

int main(){
printf("nhap so can check");
scanf("%d",&numCheck2);
    a2=0;b2=1;
while(a2<= 9){
    Fibonacci(a2,b2,numCheck2);
    b2++;
     a2++;
}
}