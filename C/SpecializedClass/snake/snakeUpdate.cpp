#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


char nameFileIN[50] = "D:/code/InputOutput/snake.txt";

char nameFileOUT[50] = "D:/code/InputOutput/snakeOut.txt";


struct way{
  bool up = 1;
  bool down = 1;
  bool left = 1;
  bool right = 1;
}; way w[10];

struct table{
    bool block[10][10];
    bool snakeWay[10][10];
};table t[10];


int x[10],y[10];
int check[10];
int step[10000];
bool lever[10];





int translate(char c){
    switch (c){
    case 'A':
        return 1;
        break;
    case 'B':
        return 2;
        break;
    case 'C':
        return 3;
        break;
    case 'D':
        return 4;
        break;
    case 'E':
        return 5;
        break;
    case 'F':
        return 6;
        break;
    case 'G':
        return 7;
        break;
    case 'H':
        return 8;
        break;
    
    default:
        break;
    }
    return 0;
}







void input(char nameFile[50]){
    FILE *f; int blackBlock,x,y; char c;
    if((f=fopen(nameFile,"r"))== NULL) exit(0);
    fscanf(f,"%d",&blackBlock);
    for(int i=0;i<=blackBlock;i++){
        fscanf(f,"%c%d",&c,&x);
        y = translate(c);
        if(isspace(c)!=0){
            i--;
            continue;
        }
		t[0].block[x][y]= false;
    }

    for(int i = 0; i<= 9; i++){
        t[0].block[i][0] = false;
        t[0].block[0][i] = false;
        t[0].block[i][9] = false;
        t[0].block[9][i] = false;
    }
    for(int i = 0; i<= 9; i++){
        t[0].snakeWay[i][0] = false;
        t[0].snakeWay[0][i] = false;
        t[0].snakeWay[i][9] = false;
        t[0].snakeWay[9][i] = false;
    }
    fclose(f);
}
void Output( int step1, int step2){
    FILE *f = fopen(nameFileOUT,"w");
    fprintf(f,"%d\n",step1-1);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            fprintf(f,"%d ",t[0].snakeWay[i][j]);
            if(j==9){  
                fprintf(f,"\n");
            }
        }
    }

    fprintf(f,"\nblock\n");

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            fprintf(f,"%d ",t[0].block[i][j]);
            if(j==9){  
                fprintf(f,"\n");
            }
        }
    }
    fprintf(f,"%d\n",step2);
    for(int i = 0; i<= 9; i++) fprintf(f,"%d  ",step[i]);
    fclose(f);

}








void recoveryT(){
   for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            t[0].block[i][j] = t[1].block[i][j];
            t[0].snakeWay[i][j] = t[1].snakeWay[i][j];
        }
    }
    step[0] = step[3];
    x[0] = x[3];
    y[0] = y[3];
}
void backupT(){
   for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            t[1].block[i][j] = t[0].block[i][j];
            t[1].snakeWay[i][j] = t[0].snakeWay[i][j];
        }
    }
    step[3] = step[0];
    x[3] = x[0];
    y[3] = y[0];
}


void clearTable(){
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            t[0].block[i][j] = 1;
            t[0].snakeWay[i][j] = 1;
        }
    }
}
void clearVariable(){
    step[0] = 0;
    x[0] = 1;
    y[0] = 1;
    for(int i =0; i <= 9; i++) check[i] = 0;
    check[9] = 5;
}
void turnTrue(){
    w[0].up=1;
    w[0].down=1;
    w[0].right=1;
    w[0].left=1;
}
void turnFalse(){
    w[0].up=0;
    w[0].down=0;
    w[0].right=0;
    w[0].left=0;
}
void saveStep(){
    step[check[9]] = step[0];
    check[9]++;
}
void findMaxStep(){
    for(int i = 5; i<= check[9]; i++){
        if(step[0] < step[i]) step[0] = step[i];
    }
}


int moveDown(){
    if(t[0].block[x[0]+1][y[0]]== true){
        while(t[0].block[x[0]+1][y[0]] == true){
            t[0].snakeWay[x[0]+1][y[0]] = false;
            x[0]++;
            step[0]++;
        }
    } return 0;
}
int moveUp(){
    if(t[0].block[x[0]-1][y[0]]== true){
        while(t[0].block[x[0]-1][y[0]]== true){
            t[0].snakeWay[x[0]-1][y[0]] = false;
            x[0]--;
            step[0]++;
        }
    } return 0;
}
int moveRight(){
    if(t[0].block[x[0]][y[0]+1]== true){
        while(t[0].block[x[0]][y[0]+1]== true){
            t[0].snakeWay[x[0]][y[0]+1] = false;
            y[0]++;
            step[0]++;
        }
    } return 0;
}
int moveLeft(){
    if(t[0].block[x[0]][y[0]-1]== true){
        while(t[0].block[x[0]][y[0]-1]== true){
            t[0].snakeWay[x[0]][y[0]-1] = false;
            y[0]--;
            step[0]++;
        }
    } return 0;
}



int aQuestion(){
    if(w[0].down == true){
        moveDown();
        if(t[0].snakeWay[x[0]+1][y[0]] == false) return 0;
        turnFalse();
        w[0].right = true;
        aQuestion();
    }
    if(w[0].right == true){
        moveRight();
        if(t[0].snakeWay[x[0]][y[0]+1]== false) return 0;
        turnFalse();
        w[0].up = true;
        aQuestion();
    }
    if(w[0].up == true){
        moveUp();
        if(t[0].snakeWay[x[0]-1][y[0]]== false) return 0;
        turnFalse();
        w[0].left = true;
        aQuestion();
    }
    if(w[0].left == true){
        moveLeft();
        if(t[0].snakeWay[x[0]][y[0]-1]== false) return 0;
        turnFalse();
        w[0].down = true;
        aQuestion();
    }
    return 0;
}





int bQuestion(){
        backupT();
    if(w[0].down == true){
        moveDown();
        if(t[0].snakeWay[x[0]+1][y[0]] == false){
            if(lever[0] == false){
                saveStep();
                lever[0] = true;
                recoveryT();
                turnFalse();
                w[0].up = true;
                bQuestion();
            }
        }
        if(t[0].snakeWay[x[0]+1][y[0]] == false){
            return 0;
        }
        turnFalse();
        w[0].right = true;
        bQuestion();
    }

    if(w[0].right == true){
        moveRight();
        if(t[0].snakeWay[x[0]][y[0]+1]== false){
            if(lever[0] == false){
                saveStep();
                lever[0] = true;
                recoveryT();
                turnFalse();
                w[0].left = true;
                bQuestion();
            }
        }
        if(t[0].snakeWay[x[0]][y[0]+1]== false){
            return 0;
        }
        turnFalse();
        w[0].up = true;
        bQuestion();
    }

    if(w[0].up == true){
        moveUp();
        if(t[0].snakeWay[x[0]-1][y[0]]== false){
            if(lever[0] == false){
                saveStep();
                lever[0] = true;
                recoveryT();
                turnFalse();
                w[0].down = true;
                bQuestion();
            }
        }
        if(t[0].snakeWay[x[0]-1][y[0]]== false){
            return 0;
        }
        turnFalse();
        w[0].left = true;
        bQuestion();
    }

    if(w[0].left == true){
        moveLeft();
        if(t[0].snakeWay[x[0]][y[0]-1]== false){
            if(lever[0] == false){
                saveStep();
                lever[0] = true;
                recoveryT();
                turnFalse();
                w[0].right = true;
                bQuestion();
            }
        }
        if(t[0].snakeWay[x[0]][y[0]-1]== false){
            return 0;
        }
        turnFalse();
        w[0].down = true;
        bQuestion();
    }
    return 0;
}







// bQuestion
/*
check all way and save step then search max way
*/
















// testing+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void OutputBlock(){
    FILE *f = fopen(nameFileOUT,"w");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            fprintf(f,"%d ",t[0].block[i][j]);
            if(j==9){  
                fprintf(f,"\n");
            }
        }
    }
    fclose(f);
}
void OutputWay(){
    FILE *f = fopen(nameFileOUT,"w");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            fprintf(f,"%d ",t[0].snakeWay[i][j]);
            if(j==9){  
                fprintf(f,"\n");
            }
        }
    }
    fclose(f);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


int main(){
    clearTable();
    input(nameFileIN);
    clearVariable();
    turnTrue();
    t[0].snakeWay[x[0]][y[0]] = false;
    aQuestion();
    step[4] = step[0];

    clearTable();
    input(nameFileIN);
    clearVariable();
    turnTrue();
    t[0].snakeWay[x[0]][y[0]] = false;
    bQuestion();

    findMaxStep();

    printf("nnnn");

   Output(step[4],step[0]);

    // clearTable();
    // input(nameFileIN);
    // OutputBlock();
    // OutputWay();
    // Output(1);
return 0;
}