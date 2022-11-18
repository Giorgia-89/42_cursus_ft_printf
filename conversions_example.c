#include <stdio.h>

int main ()
{
	//to write a number:
	printf("Number %d\n", 90);
	printf("Number %i\n", 90);

	//to convert the int arg to an unsigned char - numbers must be within ascii values
	printf("Char: %c\n", 90);

	//the following outputs 5 with pipes on either side
	printf("|||%d|||\n", 5);
	//the following outputs 5 preceded by 2 zeros (width set to three digits)	
	printf("|||%03d|||", 5);
	//the following specifies the width - %10d allocates 10 space chars
	printf("|||%10d|||\n", 5);
	//the following flag left aligns the output - useful for outputting tables
	printf("|||%-10d|||\n", 5);
	//the following adjusts the precision - how many decimals
 	printf("|||%-8.3f|||\n", 5.72);
	
	return(0);
}