#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
bool tree[10000000];
char **S,**T,**O;
int diff_node = 0;

// int convert(char c){
//     if(c == 76 ) return 1;//L
//     if(c == 82) return 2;//R
//     if(c == 85) return 0;//U
//     return -1;
// }

int input(){
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
    fclose(f);
    return temp;
}
int laytohop(int vitri){
    int vitri1 =0, vitri2 = 0;
    for(int a = 1; a <= strlen(T[vitri]); a++){
        O = (char **)malloc(2*sizeof(char *));
        for(int j = 0; j < a; j++){
            O[vitri1] = (char *)malloc(2*sizeof(char));
            O[vitri1][vitri2] = T[vitri][j];
            vitri2++;
        }
        vitri1++;
        vitri2 = 0;
    }
    for(int i = 0; i < vitri1; i++){
        printf("%s",O[i]);
    }
    return vitri1;
}
int visit(char c,int root){
    if(c == 76){
        root *=2;
        if(tree[root] == 0) diff_node++;
        tree[root] = 1;

    }
    if(c == 82){
        root = root*2+1;
        if(tree[root] == 0) diff_node++;
        tree[root] = 1;
    }
    if(c == 85){
        if(root % 2 == 0) root = root /2;
        else root = (root -1)/2;
    }
    return root;
}

int main(){
int so_cap = input();
int root = 0;
for(int i = 0;i<so_cap;i++){
    for(int j = 0;j < strlen(S[i]) ; j++){
        root = visit(S[i][j],root);
    }
    diff_node = 0;
    for(int j = 0;j < strlen(T[i]); j++){
        root = visit(T[i][j],root);
    }
    printf("%d\n",diff_node+1);
    diff_node = 0;
}
laytohop(4);

} 