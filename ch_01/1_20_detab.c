/*
Exercise 1-20: Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?


I replace tabs with 'X', just because it's easier to see and debug in some cases. This can be changed by altering tab_component in main().
*/
#include <stdio.h>

#define MAXINPUTLEN 1000
#define TABLEN 8

int get_line(char[]);

int main()
{
	char tab_component = 'X';
	char line[MAXINPUTLEN];
	char new_line[MAXINPUTLEN*TABLEN];

	while ((get_line(line)) != 0)
	{
		int i = 0;
		int j = 0;
		
		while (line[i] != '\0' && line[i] != '\n')
		{
			if (line[i] == '\t')
			{				
				int spaces = TABLEN - j%TABLEN;
				for (int k = 0; k < spaces; k++)
				{
					new_line[j] = tab_component;
					++j;
				}	
				++i;
			}
			else
			{
				new_line[j] = line[i];
				++j;	
				++i;
			}
		}

		if (line[i] == '\n')
		{
			new_line[j] = '\n';
			j++;
		}
	
		new_line[j] = '\0';
		
		printf("%s", new_line);
	}
}



int get_line(char line[])
{
	int i;
	int c;

	for (i = 0; i < MAXINPUTLEN-1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		line[i] = c;
	}

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	
	return i;
}
