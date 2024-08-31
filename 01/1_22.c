/*
Exercise 1-22: Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
*/


#include <stdio.h>


int get_line(char []);

#define INPUTLEN 1000
#define LINELEN 15 //This is pretty short, to make debugging easier



int main()
{
	int len = 0;

	char line[INPUTLEN];
	char output[INPUTLEN + (INPUTLEN/LINELEN) + 1]

	while ((len = get_line(line)) != 0)
	{
		int i = 0;
		int j = 0;
		while (line[i] != '\0' && line[i] != EOF)
		{
			





		printf("%s", line);
	}

}





int get_line(char line[])
{
	int i, c;


	for (i = 0; i < INPUTLEN - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		line[i] = c;
	}

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';
}
