/*
1-13

Write a program to print a historgram of the lengths of words in it's input. It is easy to draw the historgram with the bars horizontal; a vertical orientation is more challenging.
*/

#include <stdio.h>


/*
One challenge of this problem is figuring out how large the historgram array needs to be.

Currently, the only tools the book has introduced for reading input require me to read and print one character at a time, and I have no way to store input for future reference. Of course, C has ways to do this, but I will try to complete the assignment with the tools provided.

If I could iterate through the input multiple times, I would iterate twice: once to count the length of the longest word, and once to sum up the occurences of various lengths of word.

Instead, I will simply assume a max size of 26, which has it's downsides.

In this iteration I will try to make the histogram vertical.
*/
int main()
{
	//Get length of longest word	
	int c;
	int max_word_length = 26;
	
	int word_lengths[max_word_length];

	for (int i = 0; i < max_word_length; i++)
	{
		word_lengths[i] = 0;
	}

	//Find the word lengths
	int cur_word_length = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			++word_lengths[cur_word_length];
			cur_word_length = 0;
		}
		else
		{
			++cur_word_length;
		}
	}

	//Print the historgram

	//Step 1: get height of historgram by finding highest word lenght count
	int max_word_count = 0;
	for (int i = 0; i < max_word_length; i++)
	{
		if (word_lengths[i] > max_word_count)
		{
			max_word_count = word_lengths[i];
		}
	}

	//Step 2: print the historgram + Y-axis line-by-line, starting at the top
	for (int cur_line = max_word_count; cur_line > 0; cur_line--)
	{
		printf("%3d|", cur_line);
		for (int i = 1; i < max_word_length; i++)
		{
			//width of each print should equal the width of the X-axis digits + 1
			if (cur_line - word_lengths[i] <= 0)
			{
				printf("  *"); 
			}
			else
			{
				printf("   ");
			}
		}
		printf("\n");
	}

	//Step 3: print the axis
	printf("   |"); //number of spaces equals the width each Y-axis label
	for (int i = 1; i < max_word_length; i ++)
	{
		printf("|%2d", i);
	}

	printf("|\n");



	















}
