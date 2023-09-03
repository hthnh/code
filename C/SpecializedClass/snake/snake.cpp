#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int table[10][10],table1[10][10];

// tham số vị trí của table
int x=1,y=1;
// tham số vị trí của table1
int x1=1,y1=1;
// bước đi của rắn
int step=0,step1=0;



// dịch vị trí của trục Y
int translate(char c){
    switch (c)
    {
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



// nhập table
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
		table[x][y]= 2;
    }

    for(int i = 0; i<= 9; i++){
        table[i][0] = 2;
        table[0][i] = 2;
        table[i][9] = 2;
        table[9][i] = 2;
    }
    fclose(f);
}
// nhập kết quả
void Output(char nameFile[50], int step1,int step2){
    FILE *f = fopen(nameFile,"w");
    fprintf(f,"%d\n",step1);
    fprintf(f,"%d",step2);
    fclose(f);
}
// nhân bản table ra table1
void transferTabletoTable1(){
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            table1[i][j] = table[i][j];
        }
    }
}
//chuyển table1 về table
void transferTable1toTable(){
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            table[i][j] = table1[i][j];
        }
    }
}
//xóa table
void clearTable(){
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            table[i][j] = 0;
        }
    }
}



//đi xuống đến hết ô
void moveDown(){
    while(table[x+1][y]== 0){
        table[x+1][y] = 1;
        x++;step++;
    }
}
//đi lên đến hết ô
void moveUp(){
    while(table[x-1][y]== 0){
        table[x-1][y] = 1;
        x--;step++;
    }
}
//đi phải đến hết ô
void moveRight(){
    while(table[x][y+1]== 0){
        table[x][y+1] = 1;
        y++;step++;
    }
}
//đi trái đến hết ô
void moveLeft(){
    while(table[x][y-1]== 0){
        table[x][y-1] = 1;
        y--;step++;
    }
}


void moveDown1(){
    while(table1[x1+1][y1]== 0){
        table1[x1+1][y1] = 1;
        x1++;step1++;
    }
}

void moveUp1(){
    while(table1[x1-1][y1]== 0){
        table1[x1-1][y1] = 1;
        x1--;step1++;
    }
}

void moveRight1(){
    while(table1[x1][y1+1]== 0){
        table1[x1][y1+1] = 1;
        y1++;step1++;
    }
}
void moveLeft1(){
    while(table1[x1][y1-1]== 0){
        table1[x1][y1-1] = 1;
        y1--;step1++;
    }
}
//chọn hướng xa nhất giữa trái và phải
void moveLeftOrRight(){
    transferTabletoTable1();
    step1 = step;
    x1 = x; y1 = y;
    moveLeft();
    moveRight1();

    if(step < step1){
       step = step1;
       x = x1; y = y1;
        transferTable1toTable();
    }
}
//chọn hướng xa nhất giữa lên và xuống
void moveUpOrDown(){
    transferTabletoTable1();
    step1 = step;
    x1 = x; y1 = y;
    moveDown();
    moveUp1();

    if(step < step1){
        step = step1;
        x = x1; y = y1;
        transferTable1toTable();
    }
}



int main(){
//tên file nhập
char nameFileIN[50] = "D:/code/InputOutput/snake.txt";
//tên file xuất
char nameFileOUT[50] = "D:/code/InputOutput/snakeOut.txt";
int up=0,down=0,right=0,left=0,check =1,check1 =1,stepLastA;
input(nameFileIN);

table[x][y] = 1; // start
// alway turn left

do{
    MOVE:
        if(down == 0){
            if(table[x+1][y]== 0){
                moveDown();
                stepLastA = step;
                down++;up=0;
                if(table[x+1][y]== 1) goto OUT;
                goto MOVE;
            }
        }
        if(right == 0){
            if(table[x][y+1]== 0){
                moveRight();
                stepLastA = step;
                right++;left=0;
                if(table[x][y+1]== 1) goto OUT;
                goto MOVE;
            }
        }
        if(up == 0){
            if(table[x-1][y]== 0){
                moveUp();
                down=0;up++;
                stepLastA = step;
                if(table[x-1][y]== 1) goto OUT;
                goto MOVE;
            }
        }
        if(left == 0){
            if(table[x][y-1]== 0){
                moveLeft();
                left++;right=0;
                stepLastA = step;
                if(table[x][y-1]== 1) goto OUT;
                goto MOVE;
            }
        }
    ;
    check=2;
}while (check == 1);





startMove2:
;
x=1;y=1;;up=0;down=0;right=0;left=0;check=1;
clearTable();
input(nameFileIN);

table[x][y] = 1; // start

//long way
do{
    MOVE2:
        if(table[x+1][y]== 0){
            moveUpOrDown();
            if(table[x+1][y]== 1) goto OUT;
            goto MOVE2;
        }
        if(table[x][y+1]== 0){
            moveRight();
            if(table[x][y+1]== 1) goto OUT;
            goto MOVE2;
        }
        if(table[x-1][y]== 0){
            moveUp();
            if(table[x-1][y]== 1) goto OUT;
            goto MOVE2;
        }
        if(table[x][y-1]== 0){
            moveLeft();
            if(table[x][y-1]== 1) goto OUT;
            goto MOVE2;
        }
    ;
    check=2;
}while (check == 1);

OUT:
    if(check1 == 1){
        check1++;
        goto startMove2;
    }
;

Output(nameFileOUT,stepLastA,step);

for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d ",table[i][j]);
            if(j==9){
                printf("\n");
            }
        }
}
return 0;
}