/*
2-4. Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches any character in the string s2.
*/



#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXINPUTLEN 100

void squeeze(char s1[], char s2[]);
int is_element_of(int c, char set[]);

int main()
{
	printf("Please enter the first string: ");
	char s1[MAXINPUTLEN];
	fgets(s1, MAXINPUTLEN, stdin);

	printf("\nPlease enter the set of characters to be removed from the previous string: ");
	char s2[MAXINPUTLEN];
	fgets(s2, MAXINPUTLEN, stdin);

	squeeze(s1, s2);

	printf("\nThe modified string is: %s\n", s1);
}


void squeeze(char s1[], char s2[])
{
	int i, j;

	for (i = j = 0; s1[i] != '\0'; i++)
	{
		if (is_element_of(s1[i], s2) == FALSE)
		{
			s1[j++] = s1[i];	
		}
	}
	s1[j] = '\0';
}


int is_element_of(int c, char set[])
{
	int contains = FALSE;
	for (int i = 0; set[i] != '\0'; i++)
	{
		if (set[i] == c)
		{
			contains = TRUE;
		}
	}
	return contains;
}
