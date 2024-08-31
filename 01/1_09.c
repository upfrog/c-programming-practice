#include <stdio.h>

/*
Write a program to copy it's input to it's output, replacing each string of
one or more blanks by a single blank
*/

int main()
{
	int c;
	int last_was_space = 0;

	while ((c = getchar()) != EOF)
	{

		if (c == ' ' && last_was_space == 0)
		{
			putchar(c);
			last_was_space = 1;
		}
		else if (c == ' ' && last_was_space == 1)
		{
			//do nothing
		}
		else
		{
			putchar(c);
			last_was_space = 0;
		}
	}
}
