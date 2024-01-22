#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **S,**T;
// int convert(char c){
//     if(c == 76 ) return 1;//L
//     if(c == 82) return 2;//R
//     if(c == 85) return 0;//U
//     return -1;
// }
void input(){
    FILE *f = fopen("BTREE.INP","r");
    int temp;char temp1[100000];
    fscanf(f,"%d",&temp);
    S = (char **)malloc(temp * sizeof(char *));
    T = (char **)malloc(temp * sizeof(char *));
    for(int i = 0; i < temp; i++){
        fscanf(f,"%s",temp1);
        S[i] = (char *)malloc(sizeof(temp1));
        strcpy(S[i],temp1);

        fscanf(f,"%s",temp1);
        T[i] = (char *)malloc(sizeof(temp1));
        strcpy(T[i],temp1);

    }
    for(int i = 0; i < temp; i++){
        printf("%s\n",S[i]);
        printf("%s\n\n",T[i]);
    }
}

int main(){
input();
}