#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
char **S, **T;
typedef bool item;
int diff_node;
struct Node{
    item key;
    struct Node *Left, *Right, *root;
};

typedef struct Node *Tree;

struct Node* makeNode(struct Node *p, item x){
    p = (struct Node*)malloc(sizeof(struct Node));
    p->key = x;
    p->Left = p->Right = NULL;
    return p;
}
struct Node* createNode(Tree root, Tree p, item x){
    p=  makeNode(p,x);
    p->root = root;
    return p;      
}

int input(){
    FILE *f = fopen("BTREE.INP", "r");
    int temp; char temp1[100005];
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
    return temp;
}

void reset_value(Tree Tr){
    if(Tr!=NULL){
        if(Tr->key)Tr->key = 0;
        reset_value(Tr->Left);
        reset_value(Tr->Right);
    }
}

void NLR(Tree Tr){
    if(Tr!=NULL){
        if(Tr->key)diff_node ++;
        NLR(Tr->Left);
        NLR(Tr->Right);
    }
}

void output(int x,Tree Tr){
    FILE *f = fopen("BTREE.OUT","a");
    diff_node = 0;
    NLR(Tr);
    fprintf(f,"%d  ",diff_node);
    fclose(f);
}



    
char* next(char* buffer){
    for(int i = strlen(buffer) - 1; i>=0; i--){
        if(buffer[i] =='0'){
            buffer[i] = '1';
            return buffer;
        }else{
            buffer[i] = '0';
        }
    }
    return NULL;
}

struct Node * leftChild(Tree Tr){
    if(T!=NULL)return Tr->Left;
    else return NULL;
}
struct Node * rightChild(Tree Tr){
    if(T!=NULL)return Tr->Right;
    else return NULL;
}

struct Node * rootChild(Tree Tr){
    if(T!=NULL)return Tr->root;
    else return NULL;
}


Tree visit(char c,Tree Tr, bool yn){//76L 82R 85U
    struct Node *p = Tr ;
    if(c == 76){
        if(Tr->Left == NULL) Tr->Left = createNode(p,Tr->Left, 0); 
        Tr = leftChild(Tr);
        if(yn) Tr->key = 1;
        return Tr;
    }
    if(c == 82){
        if(Tr->Right == NULL) Tr->Right = createNode(p,Tr->Right,0);
        Tr = rightChild(Tr);
        if(yn) Tr->key = 1;
        return Tr;
    }
    if(c == 85 && Tr->root != NULL){
        Tr = rootChild(Tr);
        if(yn) Tr->key = 1;
        return Tr;
    }
    return Tr;
}

struct Node *visitOmega(int size,Tree Tr, char *t){
    char s[size],temp;
    for (int i = 0; i < size; i++)
        s[i] = '0';
    s[size] = '\0';
    struct Node *t_root = NULL;
    for(int i = 0; i < pow(2,size); i++){
        t_root = Tr;
        for(int j = 0; j < size; j++){
            if(s[j] == '1') temp = t[j]; else continue;
            t_root = visit(temp,t_root,1);
        }
        next(s);
    }
    return NULL;
}



int main(){
    int so_cap = input();
    Tree Tr = NULL,temp = NULL;
    Tr = makeNode(Tr, 0);
    for(int i = 0;i<so_cap;i++){
        temp = Tr;
        for(int j = 0;j < strlen(S[i]) ; j++){
            Tr = visit(S[i][j],Tr,0);
        }
        Tr->key = 1;
        visitOmega(strlen(T[i]),Tr,T[i]);
        output(diff_node,temp);
        reset_value(temp);
        Tr = temp;
    }

}