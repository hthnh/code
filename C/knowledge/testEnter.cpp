#include <stdio.h>

int main(){
FILE *f; int a,b;
f = fopen("D:/code/InputOutput/iii.inp","r");
for(int i = 0; i<10; i++){
fscanf(f,"%c",&a);
b = (int)a;
printf("|%d  |%c| |, ",b, a);
}
fclose(f);
return 0;
}

