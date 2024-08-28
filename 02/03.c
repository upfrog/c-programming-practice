/*
Exercise 2-3. Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or OX) into it's equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
*/

/*
Potential improvements:

1) The need to make the prefix (0x/OX) optional means that if the user excludes it, they can overflow an int - or even a long. This could be fixed by observing whether or not the number has the prefix, and then adjusting the maximum allowable length. It could also be resolved by stripping the prefix.

2) Validation might be better handled in a seperate function, especially since checking if a string conforms to hexadecimal formatting is a task which may be useful in other contexts.
*/

#include <stdio.h>

#define MAXINPUTLEN 12 //10 characters for the number, plus a newline, plus a null terminator.
#define TRUE 1
#define FALSE 0

int htoi(char[]);

int main()
{
	char hex[MAXINPUTLEN]; //+1 for a null terminator.

	//Later, we will rely on all non-number parts of the string being \0.
	for (int j = 0; j <= MAXINPUTLEN; j++)
	{
		hex[j] = '\0';
	}

	/*
	Core loop. This takes and validates input, calls htoi() to convert it, then prints the result.
	*/
	while (fgets(hex, MAXINPUTLEN, stdin)  != NULL)
	{
		//Validation	
		int i = 0;
		int isvalid = TRUE;
		
		for (i; i < MAXINPUTLEN && hex[i] != '\n' && hex[i] != '\0'; i++)
		{
			//Checks if a character is not a digit.
			if (!((hex[i] >= '0' && hex[i] <= '9')
				|| (hex[i] >= 'A' && hex[i] <= 'F')
				|| (hex[i] >= 'a' && hex[i] <= 'f')))
			{
				//Given that a character is not a digit, checks if it is a valid prefix.
				if (!((i == 0 || i == 1) && ((hex[0] == '0' && hex[1] == 'x') || (hex[0] == 'O' && hex[1] == 'X'))))
				{
					isvalid = FALSE;
				}
				else
				{
					++i;
				}
			}
		}

		//If the last non-null char is not \n, then the input may have been too long.
		if (hex[i] != '\n')
		{
			isvalid = FALSE;
		}

		hex[i] = '\0';

		if (isvalid == TRUE)
		{
			printf("The integer value is: %d\n", htoi(hex));
		}
		else
		{
			printf("not valid\n");
		}

		for (int j = 0; j <= MAXINPUTLEN; j++)
		{
			hex[j] = '\0';
		}
	}
}


int htoi(char hex[])
{
	long sum = 0;	
	int start = MAXINPUTLEN;

	while (start > 0 && hex[start] == '\0')
	{
		--start;
	}

	int place = 0;

	while (((start-place)>= 0)) 
	{
		int cur = start-place;
		long term = 0;	
		//Distinguish the character type.
		if (hex[cur] == 'X' || hex[cur] == 'x')
		{
			place = place + 2;
		}
		else if (hex[cur] >= '0' && hex[cur] <= '9')
		{
			term = hex[cur] - '0';		
		}
		else if (hex[cur] >= 'A' && hex[cur] <= 'F')
		{
			term = hex[cur] - '7';	
		}
		else if (hex[cur] >= 'a' && hex[cur] <= 'f')
		{
			term = hex[cur]-'W';
		}
		
		for (int i = 0; i < place; i++)
		{
			term = term * 16;
		}
		
		sum = sum + term;
		place++;
	}
	return sum;
}
















