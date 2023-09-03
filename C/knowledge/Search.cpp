#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int checkSize(char nameFile[50]){
    int a= 0, b = 0, c;
    FILE *f = fopen(nameFile,"r");
    while(1) {
        c = fgetc(f);
        if( feof(f) ){ 
            break ;
        }
        if(isspace(c)!= 0)b=0;
        if(isspace(c)==0){// if it is not while space it will back == 0
            a++;
            b++;
        }
        if(b > 1) a--;
       
    }
    fclose(f);
return a;
}

// arrayInput(numInput,nameFile)
void arrayInput(int *numInput, char nameFile[50]) {
    FILE *f = fopen(nameFile,"r");
    int i = 0;
    int n = 0;
    n = checkSize(nameFile);
    numInput = (int*)calloc(n, sizeof(int));
    while(!feof(f)){
        fscanf(f,"%d",*(numInput + i));
        i++;
    }
    fclose(f);
    free(numInput);
}



int main(){
    int *numInput;
    char nameFile[50] = "D:/code/InputOutput/numArray.txt";
    arrayInput(numInput,nameFile);
    for(int i = 0; i <= checkSize(nameFile); i++)
        printf("%d  1", *numInput + i);

return 0;
}