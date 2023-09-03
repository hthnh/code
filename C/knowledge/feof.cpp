#include <stdio.h>
#include <ctype.h>

int main () {
   FILE *fp;
   int c,a;

   if((fp = fopen("D:/code/InputOutput/file.txt","r")) == NULL) {
      perror("Error in opening file");
      return(-1);
   }
   
   while(1) {
      c = fgetc(fp);
      if( feof(fp) ) { 
         break ;
      }
      if(isspace(c) == 0)a++;
      printf("%c", c);
   }
   fclose(fp);
   printf(" so luong phan tu la%d", a);
   return(0);
}



/* vong lap vo tan
#include <stdio.h>

int main () {
   FILE *fp;
   int c =0;
  
   fp = fopen("D:/code/InputOutput/file.txt","r");
   if(fp == NULL) {
      perror("Error in opening file");
      return(-1);
   }
   
   while(1) {
      c++;
      if( feof(fp) ) { 
         break ;
      }
      printf("%d", c);
   }
   fclose(fp);
   
   return(0);
}
*/

