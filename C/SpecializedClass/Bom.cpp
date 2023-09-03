#include <stdio.h>

int timeMax,u,f,d,numOfTrip;


int wayGo[10],wayBack[10],plus[10];


void input(){
    char temp;
    FILE *file = fopen("InOut/Marathon.inp","r");
    fscanf(file,"%d %d %d %d %d",&timeMax,&numOfTrip,&u,&f,&d);
    for(int i = 0; i < numOfTrip; ){
        fscanf(file,"%c",&temp);
        if(temp == '\n') continue;
        if(temp == 'u') wayGo[i] = u;
        if(temp == 'f') wayGo[i] = f;
        if(temp == 'd') wayGo[i] = d;
        i++;
    }
    for(int i = 0; i < numOfTrip; i++){
        if(wayGo[i] == u) wayBack[i] = d;
        if(wayGo[i] == f) wayBack[i] = f;
        if(wayGo[i] == d) wayBack[i] = u;
    }
    fclose(file);
}
int Bom(){
    int tong = 0,i;
    for( i = 0; i <= numOfTrip;i++) plus[i] = wayGo[i]+wayBack[i];
    for( i = 0; i <= numOfTrip;i++) 
        if((tong += plus[i])>=timeMax){  break; }
    return i;
}

void output(int result){
    FILE *f = fopen("InOut/Marathon.out","w");
    fprintf(f,"%d",result);
}

int main(){
    input();
    output(Bom());

}