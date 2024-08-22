/*
Exercise 2-1: Write a program to determine the ranges of char, short, int, and long variabels, both signed and unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	//unsigned, by lookup
	printf("\n===============\nUNSIGNED\n===============\n");
	printf("Char max: %d\nChar min : %d\n",UCHAR_MAX, 0);
	printf("Short max: %d\nShort min : %d\n",USHRT_MAX, 0);
	printf("Int max: %u\nInt min : %u\n", UINT_MAX, 0);
	printf("Long max : %lu\nLong min : %u\n", ULONG_MAX, 0);


	//signed, by lookup. 
	printf("\n===============\nSIGNED\n===============\n");
	printf("Char max : %d\nChar min : %d\n",SCHAR_MAX, SCHAR_MIN);
	printf("Short max : %d\nShort min : %d\n",SHRT_MAX, SHRT_MIN);
	printf("Int max : %d\nInt min : %d\n", INT_MAX, INT_MIN);
	printf("Long max : %ld\nLong min : %ld\n", LONG_MAX, LONG_MIN);

	printf("\n===============\nUNSIGNED, CALCULATED\n===============\n");

	/*
	A sign change indicates that overflow has been reached, and therefor, that the last number was the max/min.

	The downside is that this is quite slow.

	One potential alternative would be to use SIZEOF() to find the number of bits taken by a variable, and calculate the
	max and min from this. Is this what the book wanted me to do?
	*/

	//unsigned int
	unsigned int cur = 1;
	unsigned int last = 0;
	
	while (cur >= last)
	{
		++cur;
		++last;
	}
	printf("Int max: %u\n", last);
		
}

