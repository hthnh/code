#include <stdio.h>
FILE *f;
int main(){ 
    f= fopen("test.txt","a");
    fprintf(f,"test");
    fclose(f);
}