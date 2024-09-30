/*
NOT COMPLETED

Excercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literall.
*/

#include <stdio.h>

#define MAXINPUTLEN 25
#define MAXOUTPUTLEN 500

void expand(char[], char[]);
int advance(char[], int, char);	
int write_sequence(char[], int, char);


/*
After we have found the start of a sequence, we need to advance to the end of that sequence in s1.

To do that, we just advance until we hit the end of the sequence, but no further.

After that, we copy characters directly until we hit the start of the next sequence.


*/




int main()
{
	char s1[MAXINPUTLEN];
	char s2[MAXOUTPUTLEN];	
	fgets(s1, MAXINPUTLEN, stdin);


}



void expands(char s1[], s2[])
{
	int i = 0;
	int j = 0;


	while (s1[i] != '\0')
	{
		if (s1[i] == "a")
		{
				
		}
		else if (s1[i] == "A")
		{
			//same, but for A-Z
		}

		else if (s1[i] == 0 || s1[i] == "0")
		{
			//copy 0-9
		}
		else
		{
			//copy s1[] to s2

		}
	}



}


int advance(char s2[], int start, char target)
{
	while (s2[start] != target)
	{
		++start;
	}

	return start
}

	
int write_sequence(char s2[], int start, char sequence_start)
{
	
}
