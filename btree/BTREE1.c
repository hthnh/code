#include <stdio.h>
#include <stdlib.h>

typedef bool item
struct Node{
    item key;
    struct Node *Left, *Right;
};

typedef struct Node *Tree;

struct Node* makeNode(struct Node *p, item x){
    p = (struct Node*)malloc(sizeof(struc Node));
    p->key = x;
    p->Left = p->Right = NULL;
    return p;
}

struct Node*  CreateTree(struct Node *p,item x){   
    p=  makeNode(p,x);
    p->Left=CreateTree(p->Left,x);
    p->Right=CreateTree(p->Right,x);
    return p;       
}