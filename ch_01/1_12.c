/*
Write a program that prints it's input one word per line

Should the code ensure that every line has exactly one word? For example, if the input contains 3 spaces in a row, should they be treated as just one space?

Current code does not do that. It might be a good idea to expand it to handle multiple repeated spaces, but that is not the best use of time at this particular moment.
*/

#include <stdio.h>

#define IN	1
#define OUT	0

int main()
{
	int cur_char, state;

	while ((cur_char = getchar()) != EOF)
	{
		if (cur_char == ' ' || cur_char == '\n' || cur_char == '\t')
		{
			printf("\n");
		}
		else
		{
			putchar(cur_char);
		}
	}
}
