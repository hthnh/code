#include <ctype.h>
#include <stdio.h>

// doneee

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

int main(){
    int *numInput;
    char nameFile[50] = "D:/code/InputOutput/numArray.txt";
    printf("%d", checkSize(nameFile));
return 0;
}