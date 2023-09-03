#include <stdio.h>
#include <string.h>

int main(){
 FILE *f;
 char a[100];
 char s[100];
 printf("Nhap xau tuc ngu can dua vao tep: \n");
 gets(a);
 f = fopen("D:\\code\\C\\linh_tinh\\Tucngu.txt","w+");
 fputs(a,f);
 fgets(s,100,f);
 fclose(f);
 printf(s);
 return 0;
}