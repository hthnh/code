#include <stdio.h>
#include <stdlib.h> // For exit()


int main()
{
	FILE *fptr1, *fptr2;
	char filename1[50]= "D:/code/InputOutput/copyFile1.txt", c;
	char filename2[50]= "D:/code/InputOutput/copyFile2.txt";
	// Open one file for reading
	if ((fptr1 = fopen(filename1, "r")) == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}

	// Open another file for writing
	if ((fptr2 = fopen(filename2, "w")) == NULL)
	{
		printf("Cannot open file \n");
		exit(0);
	}

	// Read contents from file
	c = fgetc(fptr1);
	while (c != -1)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}

	printf("\nContents copied");

	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
