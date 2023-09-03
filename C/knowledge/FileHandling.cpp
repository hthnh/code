#include <stdio.h>
#include <stdlib.h>






/*
write into the file
*/
// int main(){
//    int num;
//    FILE *fptr;
//    fptr = fopen("C:/Users/haith/Desktop/code/InputOutput/FileHandling.txt","w");
 
//    if(fptr == NULL)
//    {
//       printf("Error!");   
//       exit(1);             
//    }
 
//    printf("Enter num: ");
//    scanf("%d",&num);
 
//    fprintf(fptr,"%d",num);
//    fclose(fptr);
 
//    return 0;
// }







/*
read the file
*/
int main()
{
   int num;
   FILE *fptr;
 
   if ((fptr = fopen("D:/code/InputOutput/FileHandling.txt","r")) == NULL){
       printf("Error! opening file");
 
       // Program exits if the file pointer returns NULL.
       exit(1);
   }
 
   fscanf(fptr,"%d", &num);
 
   printf("Value of n=%d", num);
   fclose(fptr); 

   return 0;
}







/*
read and writes
*/
// int main()
// {
//    char sentence[1000];
//    char c[1000];
//    FILE *fptr;
 
// fptr = fopen("C:/Users/haith/Desktop/code/InputOutput/FileHandling.txt", "w");
//     if(fptr == NULL)
//         {
//             printf("Error!");
//             exit(1);
//         }
// // write into file
// printf("Enter a sentence:\n");
// gets(sentence);
 
// fprintf(fptr,"%s", sentence);
// fclose(fptr);
   
// printf("------------------------------------------------------------------------------------------------------------------------------------------------------");

//     if ((fptr = fopen("C:/Users/haith/Desktop/code/InputOutput/FileHandling.txt", "r")) == NULL)
//         {
//             printf("Error! opening file");
//             // Program exits if file pointer returns NULL.
//             exit(1);         
//         }
 
// // reads text until newline 
// fscanf(fptr,"%[^\n]", c);
 
// printf("Data from the file:\n%s", c);
// fclose(fptr);
    
// return 0;
// }



// //read and write
// int main()
// {
//    char sentence[1000];
//    char c[1000];
//    FILE *fptr;
 
// fptr = fopen("D:/code/InputOutput/FileHandling.txt", "a+");
//     if(fptr == NULL)
//         {
//             printf("Error!");
//             exit(1);
//         }
// // write into file
// printf("Enter a sentence:\n");
// gets(sentence);
 
// fprintf(fptr,"%s", sentence);
// fclose(fptr);

   
// printf("------------------------------------------------------------------------------------------------------------------------------------------------------");

// fptr = fopen("D:/code/InputOutput/FileHandling.txt", "r");
//     if(fptr == NULL)
//         {
//             printf("Error!");
//             exit(1);
//         }
// // reads text until newline 
// fscanf(fptr,"%[^\n]", c);
 
// printf("Data from the file:\n%s", c);
// fclose(fptr);
    
// return 0;
// }