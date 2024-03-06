#include <stdio.h>

/*
Write a program to copy it's input to it's ouput, replacing each tab by \t, 
each backspace by \b, and each backslash by \\

Note that ctrl-h produces a backspace in the terminal input.
*/

int main()
{
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			printf("\\t");
		}
		else if (c == '\b')
		{
			printf("\\b");
		}
		
		else if (c == '\\')
		{
			printf("\\");
			printf("\\");
		}
		
		else
		{
			
			putchar(c);
		}
	}
}
