/*
Excercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in 
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either 
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that 
a leading or trailing - is taken literally.
*/

#include <stdio.h>

#define MAXINPUTLEN 25
#define MAXOUTPUTLEN 500
#define TRUE 1
#define FALSE 0

void expand(char[], char[]);
int advance(char[], int, char);	
int is_sequence(char[], int, char);
int write_sequence(char[], int, char, char);

int main()
{
	char s1[MAXINPUTLEN];
	char s2[MAXOUTPUTLEN];	
	fgets(s1, MAXINPUTLEN, stdin);
	expand(s1, s2);
	printf("%s\n", s2);
	return 0;
}

/*
Copies s1 into s2, expanding certain abbreviations.

How can I make this less painful?

I could...
- Write functions for alphatic and numeric expansions - that doesn't save me much.
- Would generalizing this code help? 
*/
void expand(char s1[], char s2[])
{
	int i = 0;
	int j = 0;
	char seq_end = NULL;

	while (s1[i] != '\0')
	{
		if (s1[i] == 'a' && is_sequence(s1, i, 'z'))
		{
			write_sequence(s2, j, 'a', 'z');
			j += 26;
			i += 3;
		}
		else if (s1[i] == 'A' && is_sequence(s1, i, 'Z'))
		{
			write_sequence(s2, j, 'A', 'Z');
			j += 26;
			i += 3;
		}
		else if ((s1[i] == 0 || s1[i] == '0') && is_sequence(s1, i, '9'))
		{
			write_sequence(s2, j, '0', '9');
			j += 10;
			i += 3;
		}
		else
		{
			s2[j] = s1[i];
			++i;
			++j;
		}
	}
}

/*
To be a valid sequence, a substring must start with the first character of the
sequence, then be followed by a dash, then the final character of the sequence.
*/
int is_sequence(char s2[], int i, char seq_end)
{
	if (i < MAXOUTPUTLEN - 1
	&& s2[i+1] == '-'
	&& s2[i+2] == seq_end)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/*
Fills a sequence of characters into s2, starting from some start index and character

Assumes that the end of the sequence has an ASCII value greater or equal to the start.
*/
int write_sequence(char s2[], int start, char sequence_start, char sequence_end)
{
	char cur_char = sequence_start;
	while (cur_char <= sequence_end)
	{
		s2[start] = cur_char;
		++start;
		++cur_char;
	}
}
