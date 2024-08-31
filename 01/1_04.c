#include <stdio.h>

int main()
{
	float fahr, celsius;
	int upper, lower, step;

	upper = 300;
	lower = 0;
	step = 20;

	celsius = lower;
	
	while (celsius <= upper)
	{
		fahr = celsius * (9.0/5.0) + 32;
		printf("%3f %6f\n", celsius, fahr);
		celsius = celsius + step;
	}
}


