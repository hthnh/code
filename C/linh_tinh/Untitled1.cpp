#include <stdio.h>
#include <math.h>
float c1,c2,c3,d;
float cvi,dtich;
main()
{
    printf("Nhap du lieu c1");
    	scanf("%f",&c1);
    printf("Nhap du lieu c2");
    	scanf("%f",&c2);
    printf("Nhap du lieu c3");
    	scanf("%f",&c3);
    if(c1,c2,c3 > 0)
    	{
    	cvi=c1+c2+c3;
    	d=cvi/2;//d nua chu vi 
    	dtich=sqrt(d*(d-c1)*(d-c2)*(d-c3));
    	printf("\nChu vi tam giac%f",cvi);
    	printf("\nDien tich tam giac%f",dtich);
    	}
    else printf("Nhap sai");
return 0;
}
