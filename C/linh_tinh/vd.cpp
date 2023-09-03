#include <stdio.h>
#include <string.h>

char xau [5];
int i;

int main()
{
    printf ("Nhập vào 1 xâu ký tự: ");
    for (i = 0; i < 5; i++)
        {
            printf ("\nNhập vào ký tự thứ %d: ", i);
            scanf ("%c", &xau[i]);
        }
    //gets (xau);
    
    printf ("Xâu vừa nhập có nội dung là: ");
   // puts (xau);
   for (i = 0; i < 5; i++)
        {
            printf ("%c", xau[i]);
           // scanf ("%c", &xau[i]);
        }
    
return 0;
}