#include <stdio.h>

char ten[100];
char lop[100];
int maso;
FILE *file;

int main(){
    printf("nhap ten cua ban: "); gets(ten);
    printf("nhap lop cua ban: "); gets(lop);
    printf("nhap ma so cua ban: "); scanf("%d",&maso);

    file = fopen("D:/code/InputOutput/capnhat.txt","a+");

    fprintf(file, "%s %s\n", "ho va ten:", ten);
    fprintf(file, "%s %s\n", "lop:", lop);
    fprintf(file, "%s %d\n\n","ma so:", maso);

    fclose(file);

return 0; 
}//haithinh