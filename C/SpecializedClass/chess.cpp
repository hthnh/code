#include <stdio.h>
char nameIn[50] = "D:\\code\\InputOutput\\Chess\\chess.in";
char nameOut[50] = "D:\\code\\InputOutput\\Chess\\chess.out";
int Match,turn,a[100],a1[100],b[100],b1[100],point = 0,maxA,maxB,localMaxA,localMaxB,localA,localB;
struct Local{
    int a;
    int b;
}; Local L[100];


void input(){
    FILE *f = fopen(nameIn,"r");
    fscanf(f,"%d",&Match); Match--;
    for(int i = 0; i <= Match; i++ ){
        fscanf(f,"%d", &a[i]);
        fscanf(f,"%d", &b[i]);
    }
}

void findLocalA(int j){
    for(int i = 0; i <= Match; i++){
        if(a[j] == a1[i]){L[turn].a = i+1; a1[i] = 0;}
    } 
}
void findLocalB(int j){
    for(int i = 0; i <= Match; i++){
        if(b[j] == b1[i]){L[turn].b = i+1; b1[i] = 0;}
    } 
}

void findMaxA(int j){
    int check = a[0];
    for(int i = 0; i <= j; i++){
        if(check <= a[i]){ 
            check = a[i];
            localMaxA = i;
        }
        maxA = check;
    }
}

void findMaxB(int j){
    int check = b[0];
    for(int i = 0; i <= j; i++){
        if(check <= b[i]){ 
            check = b[i];
            localMaxB = i;
        }
        maxB = check;
    }
}

void moveA(int j){
    int temp = a[j];
    for(int i = j; i <= Match; i++){
        a[i] = a[i+1];
    }
    a[Match] = temp;
}
void moveB(int j){
    int temp = b[j];
    for(int i = j; i <= Match; i++){
        b[i] = b[i+1];
    }
    b[Match] = temp;
}



void copyArray(){
    for(int i = 0; i <= Match; i++){
        a1[i] = a[i];
        b1[i] = b[i];
    }
}


void output(){
    FILE *f = fopen(nameOut,"w");
    fprintf(f,"%d\n",point);
    for(int i = 0; i <= Match; i++){
        fprintf(f,"%d\n",L[i].b);
    }

    fclose(f);

    
}


int main(){
    input();
    localA = Match;localB = Match;turn = 0;
    copyArray();
    while(1){
        findMaxA(localA);
        findMaxB(localB);
        if (maxA > maxB){
            if(localB == 0){
                findLocalA(localMaxA);
                findLocalB(localMaxB);
                turn++;
            }else{
            moveA(localMaxA);
            localA--;
            }
        }else if(maxA < maxB){
            findLocalA(localMaxA);
            findLocalB(localMaxB);
            moveA(localMaxA);
            moveB(localMaxB);
            localA--;localB--;point+=2;turn++;
        }else if(maxA == maxB){
            findLocalA(localMaxA);
            findLocalB(localMaxB);
            moveA(localMaxA);
            moveB(localMaxB);
            localA--;localB--;point++;turn++;
        }else if(maxA > maxB && localB == 0){
            findLocalA(localMaxA);
            findLocalB(localMaxB);
        }
        if(turn == Match+1) break;
    }


    output();
    return 0;


}