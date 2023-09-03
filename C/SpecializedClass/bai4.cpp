#include <stdio.h>

char strings[1000];
FILE *file;

int main(){
    printf("nhap vao xau ki tu IN HOA: "); gets(strings);

    file = fopen("D:/code/InputOutput/chuhoa.txt","w");

    fprintf(file, "%s", strings);

    fclose(file);

return 0; 
}//haithinh