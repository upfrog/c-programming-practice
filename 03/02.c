/*
Exercise 3-2. Write a function escape(s, t) that converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as well, converting escape sequences into the real characters.
*/


#include <stdio.h>

#define MAXINPUTLEN 1000


void escape(char[], char[]);
void reverse(char[], char[]);


int main()
{
	char t[MAXINPUTLEN];
	char s[MAXINPUTLEN*2];//All the escape sequences have to characters, so this is the max length needed.
	fgets(t, MAXINPUTLEN, stdin);

	escape(s, t);
	printf("%s\n", s);

	reverse(t, s);
	printf("After reversal:\n%s\n", t);
}

void escape(char s[], char t[])
{
	int s_i = 0;
	int t_i = 0;

	while (t[t_i] != '\0')
	{
		switch (t[t_i])
		{
			case '\t':
				s[s_i++] = '\\';
				s[s_i++] = 't';
				break;
			case '\n':
				s[s_i++] = '\\';
				s[s_i++] = 'n';
				break;
			default:
				s[s_i++] = t[t_i];
		}
		++t_i;
	}
	s[s_i] = '\0';
}

//Where t is the product of escape(), and s will become equivalent to t when it first entered escape
void reverse(char s[], char t[])
{
	int s_i = 0;
	int t_i = 0;

	while (t[t_i] != '\0')
	{
		if (t[t_i] == '\\')
		{
			switch (t[t_i+1])
			{
				case 't':
					s[s_i++] = '\t';
					t += 2;
					break;
				case 'n':
					s[s_i++] = '\n';
					t += 2;
					break;
				default:
					s[s_i++] = t[t_i++];
			}
		}
		else
		{
			s[s_i++] = t[t_i++];
		}
	}
	s[s_i] = '\0';
}




