#include <stdio.h>
#include <stdbool.h>
bool t;
bool d[10][10];
int main(){
d[3][1] = true;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            printf("%d ",d[i][j]);
            if(j==9){  
                printf("\n");
            }
        }
    }
    return 0;
}