#include <stdio.h>
#include <stdlib.h>









void Check(char nameFile[50]){
    FILE *f;int rightCheck,a=2,b;
    if((f=fopen(nameFile,"r"))== NULL) exit(0);
        while(1){
        fscanf(f,"%d",&rightCheck);

        if(rightCheck == 46) b= 1;

        switch (rightCheck){
        case 32:
            if(b == 1) break;
            a = 1;
            break;
        case 43:
            a = 1;
            break;
        case 46:
            a = 1;
            break;
        case 48:
            a = 1;
            break;
        case 49:
            a = 1;
            break;
        case 50:
            a = 1;
            break;
        case 51:
            a = 1;
            break;
        case 52:
            a = 1;
            break;
        case 53:
            a = 1;
            break;
        case 54:
            a = 1;
            break;
        case 55:
            a = 1;
            break;
        case 56:
            a = 1;
            break;
        case 57:
            a = 1;
            break;
        case 58:
            a = 1;
            break;
        case 59:
            a = 1;
            break;
        case 101:
            a = 1;
            break;
        default:
            a++;
            break;
        }

        if(a == 3){
            fprintf(f,"SAI");
            exit(0);
        }
    }
}



int main(){


}