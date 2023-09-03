#include <stdio.h>

int array[5];
int sum;
FILE *file;

int main(){
    for(int i = 0; i <= 4; i++){
        printf("nhap gia tri cua phan tu thu %d: ", i+1);   scanf("%d", &array[i]);
    }
    for(int i = 0; i <= 4; i++) sum = sum + array[i];

    file = fopen("D:/code/InputOutput/ketqua.txt","w");
    fprintf(file, "%d", sum);

    fclose(file);
}//haithinh