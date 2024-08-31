/*
Exercise 1-21: Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to read a tab stop, which should be given preference?

The prompt says "strings of blanks", which I am choosing to interpret as "strings which include blanks" - though in all fairness, a string which includes blanks can be broken down into strings of blanks, and strings which do not include blanks.
*/




#include <stdio.h>


#define INPUTLEN 1000
#define TABLEN 8


int get_line(char line[]);

int main()
{
	char input[INPUTLEN];
	char output[INPUTLEN];	

	while ((get_line(input)) != 0)
	{
		
		int i = 0;
		int j = 0;

		while (input[i] != '\0')
		{
			if (input[i] == ' ')
			{
				//determine how many spaces
				int k = 1;

				while (input[i+k] != '\0' && input[i+k] == ' ')
				{
					++k;
				}


				int last_space = i + k - 1;
			
				//Check if we have a partial tab's worth of spaces to consume
				if (k >= (TABLEN - i%TABLEN))
				{
					output[j] = '\t';
					++j;

					k = k - (TABLEN - i%TABLEN);
					i = i + (TABLEN - i%TABLEN);
				}
				
				//Fill in complete tabs, if needed
				while (k >= TABLEN)
				{
					output[j] = '\t';
					++j;
					k = k - TABLEN;
					i = i + TABLEN;
				}
				
				//Fill in spaces
				while (k > 0)
				{
					output[j] = ' ';
					++j;
					++i;
					--k;
				}
			}
			else
			{
				output[j] = input[i];
				++i;
				++j;
			}
		}
		
		output[j] = '\0';
		printf("%s", output);
	}
}


int get_line(char line[])
{
	int c;
	int i;
	
	for (i = 0; i < INPUTLEN - 1 && (c = getchar()) != EOF && c != '\0' && c != '\n'; i++)
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
