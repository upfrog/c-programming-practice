/*
Exercise 2-2: Write a loop equivalent to the for loop above without using && or ||.

The original loop is:

for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)

*/

#include<stdio.h>

int main()
{
	//One way to do this would be to nest a while loop with a series of conditionals.

	int i = 0;
	int lim = 1000;
	int c;

	while (i >= 0)
	{
		if (i < lim-1)
		{
			if ((c=getchar()) != '\n')
			{
				if (c != EOF)
				{
					++i;
					//Then do whatever else...
				}
			}
				
		}
	}
}
