#include <stdio.h>
FILE *f;
int main(){
    f= fopen("test.txt","w+");
    fprintf(f,"test");
    fclose(f);
}