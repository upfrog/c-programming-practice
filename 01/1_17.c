/*
Exercise 1-17: Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>


int getLength(char line[]);

#define MAX_LEN 1000
#define PRINT_CUTOFF 80

int main()
{
	char line[MAX_LEN];
	int len = 0;

	
	while ((len = getLength(line)) > 0)
	{
		if (len > 80)
		{
			printf("%s\n", line);
		}
	}
}

int getLength(char line[])
{
	int i, c;

	for(i = 0; i < MAX_LEN - 1 && ((c = getchar()) != EOF && c != '\n'); i++)
	{
		line[i] = c;
	}

	if (c == '\n')
	{
		line[i] = '\n';
		i += 1;	
	}


	line[i] = '\0';

	return i;
}


