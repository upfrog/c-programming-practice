/*
2-5. Write the function any(s1, s2), which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
*/

#include <stdio.h>


#define MAXINPUTLEN 100


int any(char s1[], char s2[]);


int main()
{
	char s1[MAXINPUTLEN], s2[MAXINPUTLEN];

	printf("Please enter the first string: ");
	fgets(s1, MAXINPUTLEN, stdin);
	printf("Please enter the second string: ");
	fgets(s2, MAXINPUTLEN, stdin);

	printf("index: %d\n", any(s1, s2));
}


int any(char s1[], char s2[])
{
	int i = 0;
	for (i; s1[i] != '\0'; i++)
	{
		int j = 0;	
		while (s1[i] != s2[j++] && s2[j] != '\0');
		if (s2[j] != '\0')
		{
			return i;
		}
	}
	return -1;
}
