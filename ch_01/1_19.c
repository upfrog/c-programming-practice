/*
Exercise 1-19: Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses it's input a line at a time.
*/


int get_line(char line[]);
void reverse(char line[], int len);

#define MAXLEN 1000

#include <stdio.h>

int main()
{
	char line[MAXLEN];
	int len;

	while ((len = get_line(line)) != 0)
	{
		reverse(line, len);
		printf("%s", line);
	}
}

int get_line(char line[])
{
	int c, i;

	for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; i++)
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

void reverse(char line[], int len)
{
	len = len - 2;
	int target = (len/2);
	char swap;

	for (int i = 0; i <= target; i++)
	{
		swap = line[len - i];
		line[len - i] = line[i];
		line[i] = swap;
	}
}
