/*
Exercise 1-18: Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines
*/
/* Still prints an extra \n if a single space follows a line. Also, the two if statements inf formatLine are pretty gross */


#define MAXLINE 1000

#include <stdio.h>

int getLine(char line[]);
void formatLine(char line[], int i);

int main()
{
	char line[MAXLINE];
	int i;

	while ((i = getLine(line)) != 0)
	{
		formatLine(line, i);

		if (line[0] != '\0')
		{
			printf("%s", line);
		}
	}

}


int getLine(char line[])
{
	int c, i;

	for (i = 0; i < MAXLINE-1 && ((c = getchar()) != '\n' && c != EOF); i++)
	{
		line[i] = c;
	}

	if (c == '\n')
	{
		line[i] = '\n';
		i++;
	}

	line[i] = '\0';
	return i;
}

void formatLine(char line[], int i)
{
	//If a line is just \n, then we don't need do run the main loop.	
	if (line[0] == '\n')
	{
		line[0] = '\0';
		i = -1;
	}
	
	i = i -2; //Assumes that line[i] == \0, line[i-1] == \n
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
	{
		line[i] = '\0';
		--i;
	}

	if (line[0] != '\0')
	{
		++i;
		line[i] = '\n';
		++i;
		line[i] = '\0';
	}
}
