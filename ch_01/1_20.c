/*
Exercise 1-20: Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops say for every n columns. Should n be a variable or a symbolic parameter?
*/


#include <stdio.h>

#define TABSTOPSIZE 8
#define MAXINPUTSIZE 1000

int get_input(char[]);
void detab(char[], int);


int main()
{
	char input_string[MAXINPUTSIZE];
	int c;
	int len;

	while ((len = get_input(input_string)) != 0)
	{
		printf("%s", input_string);
		detab(input_string, len);
		//printf("%s", input_string);
		//process string
		//print string
	}
}


int get_input(char input[])
{
	int c, i;

	for (i = 0; i < MAXINPUTSIZE-1 && ((c = getchar()) != EOF && c != '\n'); i++)
	{
		input[i] = c;
	}

	if (c == '\n')
	{
		input[i] = '\n';
		++i;
	}

	input[i] = '\0';

	return i;
}

void detab(char input[], int input_size)
{
	char output[TABSTOPSIZE*MAXINPUTSIZE];
	
	int i = 0;
	int j = 0;

	while (i < input_size)
	{
		printf("%d\n", i);
		if (input[i] != '\t')
		{
			output[j] = input[i];
			++i;
			++j;
		}
		else
		{
			int space = 0;
			while (space < 8)
			{
				output[j] = 'X';
				++j;
				++space;
				printf("Adding spaces!\n");
			}
			++i;
		}
		
	}
	output[i] = '\0';
	/*
	for (i = j = 0; i <= input_size; i++, j++)
	{
		if (input[i] != '\t')
		{
			output[j] = input[i];
		}
		else
		{
			//int num_space = (TABSTOPSIZE + 1) - ((j+1)%TABSTOPSIZE);
			int num_space = 8;
			while (num_space > 0)
			{
				output[j] = '|';
				++j;
				--num_space;
			}
		}
	}
	*/
	printf("input: %s\noutput:%s\n", input, output);
	input = output;
}

