/*
Write a program to print a historgram of the frequencies of different characters in it's input
*/

#include <stdio.h>

int main()
{
	int num_digits[10];
	int num_lowercase[26];
	int num_uppercase[26];

	//set array default values
	for (int i = 0; i < 10; i++)
	{
		num_digits[i] = 0;
	}

	for (int i = 0; i < 26; i++)
	{
		num_lowercase[i] = num_uppercase[i] = 0;
	}

	int cur_char = 0;
	while ((cur_char = getchar()) != EOF)
	{
		if (cur_char >= '0' && cur_char <= '9')
		{
			num_digits[cur_char-'0']++;
		}
		//tradeoff between clarity and concision: accumulate to one array, or accumulate to 2, then later add?
		else if (cur_char >= 'A' && cur_char <= 'Z')
		{
			num_uppercase[cur_char-'A']++;
		}
		else if (cur_char >= 'a' && cur_char <= 'z')
		{
			num_lowercase[cur_char-'a']++;
		}
	}

	//print historgram

	//print digits
	for (int i = 0; i < 10; i ++)
	{
		printf("%d|", i);
		
		for (int j = 0; j < num_digits[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//print letters
	for (int i = 0; i < 26; i++)
	{
		int c = i + 65;
		printf("%c|", c);
		for (int j = 0; j < num_uppercase[i] + num_lowercase[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
}	
