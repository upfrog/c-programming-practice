/*
Exercise 2-10: Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of ef-else
*/

//I couldn't find lower(), so I just wrote code that does the job.


#include <stdio.h>


int main()
{
	int c;
	while ((c = getchar()) != EOF)
	{
		putchar(((c > 64 && c < 91) ? c + 32 : c));
	}
}
