#include <stdio.h>
#include <stdlib.h>
int T[8], S[8];
void input(){
    int temp = 0,temp1 = 0;
    FILE *f = fopen("STICKERS.INP","r");
    fscanf(f,"%d",&temp);
    while(1){
        if(temp == 0) break;
        temp1 = temp%10;
        temp /=10;
        switch (temp1)
        {
        case 0:
            T[0]++;
            break;
        case 1:
            T[1]++;
            break;
        case 2:
            T[2]++;
            break;
        case 5:
            T[2]++;
            break;
        case 3:
            T[3]++;
            break;
        case 4:
            T[4]++;
            break;
        case 6:
            T[5]++;
            break;
        case 9:
            T[5]++;
            break;
        case 7:
            T[6]++;
            break;
        case 8:
            T[7]++;
            break;
        
        default:
            break;
        }
        
    }
    fscanf(f,"%d",&temp);
    while(1){
        if(temp == 0) break;
        temp1 = temp%10;
        temp /=10;
        switch (temp1)
        {
        case 0:
            S[0]++;
            break;
        case 1:
            S[1]++;
            break;
        case 2:
            S[2]++;
            break;
        case 5:
            S[2]++;
            break;
        case 3:
            S[3]++;
            break;
        case 4:
            S[4]++;
            break;
        case 6:
            S[5]++;
            break;
        case 9:
            S[5]++;
            break;
        case 7:
            S[6]++;
            break;
        case 8:
            S[7]++;
            break;
        default:
            break;
        }
    }
    fclose(f);
}

void output(int r){
    FILE *f = fopen("STICKERS.OUT","w");
    fprintf(f,"%d",r);
    fclose(f);
}

int main(){ 
    input();
    int temp = 0,min = 0, temp1 = 0;
    for(int i = 0; i < 8; i++){
        if(S[i]> 0){
            while(T[i] >= S[i]){
                T[i] -= S[i];
                temp++;
            }
            if(min > temp && temp1 > 0) min = temp; 
            if(temp1 == 0 && temp > 0){
                min = temp;
                temp1 = 1;
            }
        }
    }
        output(min);


}
