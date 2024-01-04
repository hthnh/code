#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
int gen[2][1000];
int size_of_2_gen = 0,max_gen,end_of_gen_0,end_of_gen_1, result = 0;

void input(){
    int i = 0,y = 0,c = 0;
	FILE *f = fopen("test.txt","r");char temp, temp1[3000];
	while(temp != EOF){
		while((temp = fgetc(f))!= EOF){
			if(temp == 32){
				gen[i][y] = atoi(temp1);
				memset(temp1, 0 ,sizeof(temp1));
				y++;
				size_of_2_gen++;
				c = 0;
				break;
			}
			if(temp == 10){
				gen[i][y] = atoi(temp1);
				memset(temp1, 0 ,sizeof(temp1));
				y = 0;
				size_of_2_gen++;
				c = 0;
				i++;

				break;
			}
			temp1[c] = temp;
			c++;
		}
	}
	gen[i][y] = atoi(temp1);
}
void outputcheck(){
	for( int i = 0; i < 2; i++){
		for(int y = 0; y < 100; y++){
			if(gen[i][y] == 0) break;
			printf("%d ",gen[i][y]);
		}
		printf("\n");}

}

bool songuyento(int i){
	int count = 0 ;
	if(i == 2) return true;
	for(int j = 1; j <= i; j++)
		if(i % j == 0) count++;
	if(count == 2) return true;
	else return false;
}
void removenum(int i, int y){
	for(int j = 0; j < size_of_2_gen; j++){
		gen[i][y] = gen[i][y+1];
		y++;
	}
}
void giv_end_of_gen(){
	for(int i = 0; i< size_of_2_gen; i++){
		if(gen[0][i]<=0){
			end_of_gen_0 = i;
			break;
		}
	}
	for(int i = 0; i< size_of_2_gen; i++){
		if(gen[1][i]<=0){
			end_of_gen_1 = i;
			break;
		}
	}
	if(end_of_gen_0 > end_of_gen_1)max_gen = end_of_gen_0;else max_gen = end_of_gen_1;
	
}
int main(){
	input();
	giv_end_of_gen();
	for(int i = 0; i < 2; i++)
		for(int y = 0; y <= max_gen;y++){
			if(gen[i][y] == 0)break;
			if(sqrt(gen[i][y]) == (int)sqrt(gen[i][y])) continue;
			else if(cbrt(gen[i][y]) == (int)cbrt(gen[i][y]))
					if(songuyento(cbrt(gen[i][y]))) continue;
			removenum(i,y);
			y--;
		}
	if(gen[0][0] == gen[1][0]){
		result++;
		removenum(0,0);
		removenum(1,0)
	}
	giv_end_of_gen();
	if(gen[0][end_of_gen_0] == gen[1][end_of_gen_1]){
		result++;
		removenum(0,end_of_gen_0);
		removenum(1,end_of_gen_1)
	}
	giv_end_of_gen();
	for(int y = 0; y <= max_gen; y++){
		
	}
	outputcheck();
	
	return 0;
}