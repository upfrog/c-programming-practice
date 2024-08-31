/*
This is an example from page 20.

It occured to me that I might not have thought of the way it uses IN and OUT to track spaces. Between that, and the fact that the code is referred to in problem 1-11, I thought I might as well try to re-write it from scratch.
*/

#include <stdio.h>

#define IN	1 //in a word
#define OUT	0 //outside of a word

int main()
{
	int		word_count = 0, 
			line_count = 0, 
			char_count = 0, 
			cur_char = 0, 
			status = 0;
	
	status = OUT;

	
	while ((cur_char = getchar()) != EOF)
	{
		++char_count;

		if (cur_char == '\n')
		{
			++line_count;
		}
		if (cur_char == ' ' || cur_char == '\t' || cur_char == '\n')
		{
			status = OUT;
		}
		else if (status == OUT)
		{
			status = IN;
			++word_count;
		}
	}

	printf("Word count: %3d	line count: %3d	character count: %3d\n", word_count, line_count, char_count);
}
