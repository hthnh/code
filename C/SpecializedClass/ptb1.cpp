// Khai bao
#include <stdio.h>
#include <math.h>

// Chuong trinh bac nhat
void ptb1(int a, int b)
{
    float x;
    if(a == 0 && b != 0) printf(" Phuong trinh vo nghiem \a");
    if(a == 0 && b == 0) printf(" Phuong trinh vo so nghiem\a");
    if(a != 0)
    {
        x =(float) (-b) / a;
        printf(" Phuong trinh co 1 nghiem duy nhat : \a%f", x);
    } 
}

// Phuong trinh bac hai
void ptb2(int a, int b, int c)
{
    float x; int delta;
    if(a == 0) ptb1(b,c);
    if(a != 0)
    {
        delta = b*b - (4 *a *c);
        if(delta < 0) printf(" Phuong trinh vo nghiem\a");
        if(delta == 0) 
        {
            x =(float) -b / (2*a);
            printf(" Phuong trinh co nghiem kep x1 = x2 = %.2f\a", x);
        }
        if(delta > 0)
        {
            float x1 =(float) ((-b) - sqrt(delta)) / (2*a);
            float x2 =(float) ((-b) + sqrt(delta)) / (2*a);
            printf(" Phuong trinh co 2 nghiem phan biet la: %.2f va %.2f\a", x1, x2);
        }
    }
}

int main(){
    int a,b,c;
    printf(" Chao mung ban den voi chuong trinh bien luan va tim nghiem cho phuong trinh \n\a");
    printf(" Nhap gia tri a: \a"); scanf("%d",&a);
    printf(" Nhap gia tri b: \a"); scanf("%d",&b);
    printf(" Nhap gia tri c: \a"); scanf("%d",&c);
    
    // Su dung chuong trinh con
    // printf("\nptb1");
    // ptb1(a,b); 

    printf("-------------------------------------------\n");
    ptb2(a,b,c);
    printf("\n-------------------------------------------\n");

    return 0;
}