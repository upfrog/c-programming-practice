#include <stdio.h>

/*
Write a program to count blanks, tabs, and newlines.

Note that by default, thie book expects input to be terminated
by EOF. However, this does not seem to happen automatically 
anymore. I am manually simulated this behavior by pressint
ctrl-D after entering my input.
*/

int main()
{
	int blank_count = 0, tab_count = 0, newline_count = 0;
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			++blank_count;
		}
		else if (c == '\t')
		{
			++tab_count;
		}
		else if (c == '\n')
		{
			++newline_count;
		}
	}

	printf("Blanks: %13d\nTabs: %15d\nNewlines: %11d\n", blank_count, tab_count, newline_count);
}
