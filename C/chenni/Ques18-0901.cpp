#include <stdio.h>
int Num[3000];
int end;

void Fibonacci(){
    int temp,a= 1,b = 1;

    for(int i = 0; i < end; i++){
// dãy số 1,1,2,3,5,8,13,21,..
        temp = a;
        a += b;
        b = temp;
        Num[i] = b;
    }
}

void CheckOdds(){
    int n= 0;
    for(int i = 0; i <= end; i++){
        if (Num[i] % 2 != 0) n++;
    }
    printf("co tong cong %d so le", n);
}

int main(){

    int s;
    printf("nhap vi tri muon kiem tra ");
    scanf("%d", &end);
    Fibonacci();
    CheckOdds();

    printf("\n nhap 1 va an enter de thoat chuong trinh");
    scanf("%d",&s);
return 0;
}