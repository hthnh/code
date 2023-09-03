#include<stdio.h>
#include<conio.h>
#include <ctype.h>
#include <stdlib.h>
int bang[10][10];
char Outfile[50] = "D:/code/InputOutput/snakeOut.txt";
int tran(char c){
   	if(c=='A') { return 1;}       //fix
   	else if(c=='B') { return 2;}  // fix khi return 0 thi` ha`m se k tra ve gi het ma ket thuc nen chuong trinh hieu sai
   	else if(c=='C') { return 3;}  // nen moi phai gia tri nho nhat la return 1 va cuoi ha`m phai co return 0 de k bi warning
   	else if(c=='D') { return 4;}  // sua lai ten file In Out gium nha, nay xoa de test a :)))
   	else if(c=='E') { return 5;}
   	else if(c=='F') { return 6;}
   	else if(c=='G') { return 7;}
   	else if(c=='H') { return 8;}
    else return 0;

}

 void nhap(char tenFile[100] )
{	
	char ca;
	FILE *fnhap;
	int soden,y,x;
	fnhap = fopen(tenFile,"r");
		fscanf(fnhap,"%d",&soden);
		int i;
		for(i=0;i<=soden;i++)
		{
			fscanf(fnhap,"%c%d",&ca,&x);
			y = tran(ca)-1;                   //fix, tran(ca) de khi ngdung nhap A se ra gia tri cuoi cung la 0 theo tham so cua table
		
			if(isspace(ca)!=0)
			{
			i--;
			continue;
			}
			bang[x][y+1]=1;
		}
}
void output(int step1)
{
	FILE *fxuat;
	fxuat = fopen(Outfile,"w+");
	fprintf(fxuat,"%d\n",step1);
	int i,j;
	for(i=0;i<10;i++)
	{
		bang[0][i]=8;
		bang[i][0]=8;
		bang[9][i]=8;
		bang[i][9]=8;
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++){
		fprintf(fxuat,"   %d",bang[i][j]);
		if(j==9){
			fprintf(fxuat,"\n");
			}
		}
	}
	fclose(fxuat);

	
}
int main(){
char tenFile[50] = "D:/code/InputOutput/snake.txt";
	nhap(tenFile);
	int row =1 ; int col = 1 ; int buoc=1 ; int step=0;
	while(bang[row][col]!=2 || row <= 8 || col <= 8)
	{
		if(buoc==1)
			{
				bang[row][col]=2;
				row++;
				if(bang[row][col]==1) 
				{	
					row--;
					col++;
					buoc++;	
					continue;
				}
				if(bang[row][col]==2) break;
			}
		if(buoc==2)
			{
				bang[row][col]=2;
				col++;
				if(bang[row][col]==1) 
				{	
					col--;
					row--;
					buoc++;	
					continue;
				}
				if(bang[row][col]==2) break;
			}
		if(buoc==3)
			{
				bang[row][col]=2;
				row--;
				if(bang[row][col]==1) 
				{	
					col--;
					row++;
					buoc++;	
					continue;
				}
				if(bang[row][col]==2) break;
			}
		if(buoc==4)
			{
				bang[row][col]=2;
				col--;
				if(bang[row][col]==1) 
				{	
					col++;
					row++;
					buoc++;	
					continue;
				}
				if(bang[row][col]==2) break;
			}
		if(buoc==5) buoc=1;
		
	}
	
	int i,j;
	step =0;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++){
		if(bang[i][j]==2)
		step++;
			}
		}
	

	output(step- 1);
	return 0;
	
}