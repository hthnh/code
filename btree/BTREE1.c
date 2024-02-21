#include <stdio.h>
#include <stdlib.h>

typedef bool item
struct Node{
    item key;
    struct Node *Left, *Right;
};

typedef struct Node* Tree;

struct Node* add_Node(struct Node *p, item x){
    p = (struct Node*)malloc(sizeof(struc Node));
    p->key = x;
    p->Left = p->Right = NULL;
    return p;
}

struct Node* create_Tree(Tree T, item x){
    
}