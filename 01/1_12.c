/*
Write a program that prints it's input one word per line

Code currently prints one word per line, but does not trim spaces, meaning that empty lines can occur.

Furthermore, it will skip multiple lines if you use tabs.

I don't know that this is a problem, but it's good to be aware of.
*/

#include <stdio.h>

#define IN	1
#define OUT	0

int main()
{
	int cur_char, last_char, state;
	

	while ((cur_char = getchar()) != EOF)
	{
		if ((cur_char == ' ' && last_char != ' ') || cur_char == '\n' || cur_char == '\t')
		{
			printf("\n");
		}
		else
		{
			putchar(cur_char);
		}
		last_char = cur_char;
	}
}
