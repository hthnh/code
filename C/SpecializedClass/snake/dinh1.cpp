#include<stdio.h>

int x,y,soden,i,j;
int bang[8][8];

int main(){
	printf("nhap so o den:");
	scanf("%d",&soden);
	while(soden<=1||soden>=32){
	printf("nhap so o den:");
	scanf("%d",&soden);
	}
	
	for(i=0;i<soden;i++){
		printf("Nhap toa do o den thu %d:\n",i+1);
		scanf("%d%d",&x,&y);
		while(x>8||y>8){
		printf("Nhap toa do o den thu %d:\n",i+1);
		scanf("%d%d",&x,&y);
		}
		bang[x-1][y-1]=1;
	
	}
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
		printf("%d ",bang[i][j]);
		if(j==7){
			printf("\n");
		}
	}
}
	return 0;
}