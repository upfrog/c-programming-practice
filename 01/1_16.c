/*
Exercise 1-16: Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text
*/

#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[]);
void copy(char to[], char from[]);


int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	//while ((len = getLine(line, MAXLINE)) > 0)
	int i = 0;	
	while ((len = getLine(line)) > 0) 
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
		++i;
	}
	
	if (max > 0)
	{
		printf("\nThe longest line is %d characters long. The first 999  characters of it are: \n", max);	
		printf("%s", longest);
	}

	return 0;
}


int getLine(char line[])
{
	int c, i;

	//test if you can access MAXLINE in getline() without passing it)
	for (i = 0; i < MAXLINE-1 && ((c=getchar()) != EOF && c != '\n'); i++)
	{
		line[i] = c;
	}
	
	
	if (c == '\n')
	{
		line[i] = '\n';
		++i;
	}

	line[i] = '\0';

	return i;
}

void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
	{
		++i;
	}
}












