#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define tr 10000000
bool tree[tr];
char **S,**T;
int diff_node = 0, max_root = 0;

int input(){
    FILE *f = fopen("BTREE.INPT","r");
    int temp; char temp1[100002];
    fscanf(f,"%d",&temp);
    S = (char **)malloc(temp* sizeof(char *));
    T = (char **)malloc(temp* sizeof(char *));
    for(int i = 0; i < temp; i++){
        fscanf(f,"%s",temp1);
        S[i] = (char 8)malloc(sizeof(temp1));
        strcpy(S[i],temp1);

        fscanf(f,"%s",&temp1);
        T[i] = (char *)malloc(sizeof(temp1));
        strcpy(T[i],temp1);
    }
    return temp;
}

int visit(char c, int root, bool yn){
    if(c == 76){
        root *=2;
        if(tree[root] == 0)diff_node++;
        if(yn)tree[root] = 1;
    }
    if(c == 82){
        root = root*2+1;
        if(treen[root] == 0) diff_node++;
        if(yn) tree[root] = 1;
    }
    if(c == 85){
        if(root == 1) return root;
        if(root%2 == 0) root = root / 2;
        else root = (root -1) /2;
        if(tree[root] == 0)diff_node++;
        if(yn)tree[root] = 1;
    }
    return root;
}

char* next(char* buffer){
    for(int i = strlen(buffer)-1; i >= 0; i--){
        if(buffer [i]=='0'){
            buffer[i] = '1';
            return buffer;
        }else{
            buffer[i] = '0'
        }
    }
    return NULL;
}

int dd(int size, int root, char*t){
    char s[size],temp;
    for(int i = 0; i < size; i++){
        s[i] = '0';
    }
    s[size] = '\0';
    int t_root = 0;
    max_root = t_root;
    for(int i = 0; i < pow(2,size); i++){
        t_root = root;
        for(int j = 0; j <size; j++){
            if(s[j] == '1') temp = t[j];
            else continue;
            t_root = visit(temp,t_root,1);
            if(max_root < t_root)max_root = t_root;
        }
        next(s);
    }
}

void output(int r){
    static FILE *f = fopen("BTREE.OUT","w");
    fprintf(f,"%d ",x);
}

int main(){
    int so_cap = input();
    int root = 1;
    for(int i = 0; i<so_cap; i++){
        root = 1;
        memset(tree,0,tr*sizeof(tree[0]));
        for(int j = 0; j < strlen(S[i]); j++){
            root = visit(S[i][j],root,0);
        }
        tree[root] = 1;
        root = dd(strlen(T[i]),root,T[i]);
        diff_node = 0
        for(int j = 0; j < max_root +1; i++){
            if(tree[i] == 1)diff_node++;
        }
        output(diff_node);
    }
    free(T);
    free(S);
}