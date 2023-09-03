#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(){
   char you[20];
   char checker[20]= "hello";
printf("nguoi dung nhap");
  fgets(you, sizeof(you), stdin);
// printf("bien check");
//   fgets(checker, sizeof(checker), stdin);
printf("nguoi dung nhap");
 puts(checker);
    if(strcmp(checker, you) == 0) printf("\nnice to meet you:))) so");
     else if(strcmp(checker, you) !=0 ) printf("\nsay again");
}